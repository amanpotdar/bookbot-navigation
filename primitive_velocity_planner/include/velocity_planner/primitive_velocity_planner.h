// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     https://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BOOKBOT_PRIMITIVE_VELOCITY_PLANNER_H_
#define BOOKBOT_PRIMITIVE_VELOCITY_PLANNER_H_

#include <signed_distance_field/signed_distance_field.h>
#include <trajectory_math/path.h>
#include <trajectory_math/trajectory.h>
#include <velocity_planner/velocity_planner_types.h>

namespace bookbot {

/**
 * @brief Plans a velocity profile along the desired path to generate a
 * trajectory.
 *
 * @param [in] desired_path         The fixed path the trajectory should follow
 * @param [in] robot_state          The current state of the robot
 * @param [in] params               Parameters for the velocity planning
 * @param [in] previous_trajectory  The last planned trajectory that the robot
 *                                  is currently following
 *                                  Note:
 *                                  This trajectory can follow a different path
 * @param [in] distance_fiedl       Obstacle signed distance field
 * @return Trajectory   The optimized velocity profile evaluated along the
 *                      desired path
 */
Trajectory PlanVelocityProfile(const Path& desired_path,
                               const RobotPlanningState& robot_state,
                               const VelocityPlannerParams& params,
                               const Trajectory& previous_trajectory,
                               const SignedDistanceField& distance_field);

}  // namespace bookbot

#endif  // BOOKBOT_PRIMITIVE_VELOCITY_PLANNER_H_
