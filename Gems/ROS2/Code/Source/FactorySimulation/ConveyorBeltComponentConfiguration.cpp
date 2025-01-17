/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include "ConveyorBeltComponentConfiguration.h"
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

namespace ROS2
{
    void ConveyorBeltComponentConfiguration::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<ConveyorBeltComponentConfiguration>()
                ->Version(1)
                ->Field("BeltEntityId", &ConveyorBeltComponentConfiguration::m_conveyorEntityId)
                ->Field("Speed", &ConveyorBeltComponentConfiguration::m_speed)
                ->Field("BeltWidth", &ConveyorBeltComponentConfiguration::m_beltWidth)
                ->Field("SegmentSize", &ConveyorBeltComponentConfiguration::m_segmentSize)
                ->Field("TextureScale", &ConveyorBeltComponentConfiguration::m_textureScale)
                ->Field("MaterialAsset", &ConveyorBeltComponentConfiguration::m_materialAsset)
                ->Field("GraphicalMaterialSlot", &ConveyorBeltComponentConfiguration::m_graphicalMaterialSlot);

            if (AZ::EditContext* ec = serializeContext->GetEditContext())
            {
                ec->Class<ConveyorBeltComponentConfiguration>("Conveyor Belt Component Configuration", "Conveyor Belt Component")
                    ->DataElement(
                        AZ::Edit::UIHandlers::EntityId,
                        &ConveyorBeltComponentConfiguration::m_conveyorEntityId,
                        "Conveyor Belt Entity",
                        "Entity of the conveyor belt")
                    ->DataElement(
                        AZ::Edit::UIHandlers::Default,
                        &ConveyorBeltComponentConfiguration::m_speed,
                        "Initial Speed",
                        "Initial speed of the conveyor belt")
                    ->DataElement(AZ::Edit::UIHandlers::Default, &ConveyorBeltComponentConfiguration::m_beltWidth, "Width", "Belt width")
                    ->DataElement(
                        AZ::Edit::UIHandlers::Default,
                        &ConveyorBeltComponentConfiguration::m_segmentSize,
                        "Segment Size",
                        "Size of simulated segments. Short segments might affect performance"
                        "of the physics engine.")
                    ->DataElement(
                        AZ::Edit::UIHandlers::Default,
                        &ConveyorBeltComponentConfiguration::m_textureScale,
                        "Texture scale",
                        "Scale of the texture on conveyor belt.")
                    ->DataElement(
                        AZ::Edit::UIHandlers::Default,
                        &ConveyorBeltComponentConfiguration::m_materialAsset,
                        "Physical Material",
                        "Physical Material asset of the conveyor belt")
                    ->DataElement(
                        AZ::Edit::UIHandlers::Default,
                        &ConveyorBeltComponentConfiguration::m_graphicalMaterialSlot,
                        "Graphical Material slot",
                        "The graphical material slot name to have its UV coordinates animated.")
                    ->Attribute(AZ::Edit::Attributes::DefaultAsset, &GetDefaultPhysicsMaterialAssetId)
                    ->Attribute(AZ_CRC_CE("EditButton"), "")
                    ->Attribute(AZ_CRC_CE("EditDescription"), "Open in Asset Editor")
                    ->Attribute(AZ_CRC_CE("DisableEditButtonWhenNoAssetSelected"), true);
            }
        }
    }
} // namespace ROS2
