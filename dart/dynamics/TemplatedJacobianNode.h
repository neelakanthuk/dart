/*
 * Copyright (c) 2015, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Michael X. Grey <mxgrey@gatech.edu>
 *
 * Georgia Tech Graphics Lab and Humanoid Robotics Lab
 *
 * Directed by Prof. C. Karen Liu and Prof. Mike Stilman
 * <karenliu@cc.gatech.edu> <mstilman@cc.gatech.edu>
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef KIDO_DYNAMICS_TEMPLATEDJACOBIANENTITY_H_
#define KIDO_DYNAMICS_TEMPLATEDJACOBIANENTITY_H_

#include "dart/dynamics/JacobianNode.h"

namespace kido {
namespace dynamics {

/// TemplatedJacobianNode provides a curiously recurring template pattern
/// implementation of the various JacobianNode non-caching functions. These
/// functions are easily distinguished because they return by value instead of
/// returning by const reference.
///
/// This style of implementation allows BodyNode and EndEffector to share the
/// implementations of these various auxiliary Jacobian functions without any
/// penalty from dynamic overload resolution.
template <class EntityType>
class TemplatedJacobianNode : public JacobianNode
{
public:

  // Documentation inherited
  math::Jacobian getJacobian(
      const Frame* _inCoordinatesOf) const override final;

  // Documentation inherited
  math::Jacobian getJacobian(
      const Eigen::Vector3d& _offset) const override final;

  // Documentation inherited
  math::Jacobian getJacobian(
      const Eigen::Vector3d& _offset,
      const Frame* _inCoordinatesOf) const override final;

  // Documentation inherited
  math::Jacobian getWorldJacobian(
      const Eigen::Vector3d& _offset) const override final;

  // Documentation inherited
  math::LinearJacobian getLinearJacobian(
      const Frame* _inCoordinatesOf = Frame::World()) const override final;

  // Documentation inherited
  math::LinearJacobian getLinearJacobian(
      const Eigen::Vector3d& _offset,
      const Frame* _inCoordinatesOf = Frame::World()) const override final;

  // Documentation inherited
  math::AngularJacobian getAngularJacobian(
      const Frame* _inCoordinatesOf = Frame::World()) const override final;

  // Documentation inherited
  math::Jacobian getJacobianSpatialDeriv(
      const Frame* _inCoordinatesOf) const override final;

  // Documentation inherited
  math::Jacobian getJacobianSpatialDeriv(
      const Eigen::Vector3d& _offset) const override final;

  // Documentation inherited
  math::Jacobian getJacobianSpatialDeriv(
      const Eigen::Vector3d& _offset,
      const Frame* _inCoordinatesOf) const override final;

  // Documentation inherited
  math::Jacobian getJacobianClassicDeriv(
      const Frame* _inCoordinatesOf) const override final;

  // Documentation inherited
  math::Jacobian getJacobianClassicDeriv(
      const Eigen::Vector3d& _offset,
      const Frame* _inCoordinatesOf = Frame::World()) const override final;

  // Documentation inherited
  math::LinearJacobian getLinearJacobianDeriv(
      const Frame* _inCoordinatesOf = Frame::World()) const override final;

  // Documentation inherited
  math::LinearJacobian getLinearJacobianDeriv(
      const Eigen::Vector3d& _offset,
      const Frame* _inCoordinatesOf = Frame::World()) const override final;

  // Documentation inherited
  math::AngularJacobian getAngularJacobianDeriv(
      const Frame* _inCoordinatesOf = Frame::World()) const override final;

protected:

  /// Default constructor. This is only a formality, because Entity and Frame
  /// do not offer default constructors.
  TemplatedJacobianNode();

};

} // namespace dynamics
} // namespace kido

#include "dart/dynamics/detail/TemplatedJacobianNode.h"

#endif // KIDO_DYNAMICS_TEMPLATEDJACOBIANENTITY_H_
