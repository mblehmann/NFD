/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014,  Regents of the University of California,
 *                      Arizona Board of Regents,
 *                      Colorado State University,
 *                      University Pierre & Marie Curie, Sorbonne University,
 *                      Washington University in St. Louis,
 *                      Beijing Institute of Technology,
 *                      The University of Memphis
 *
 * This file is part of NFD (Named Data Networking Forwarding Daemon).
 * See AUTHORS.md for complete list of NFD authors and contributors.
 *
 * NFD is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NFD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NFD, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NFD_DAEMON_FACE_NULL_FACE_HPP
#define NFD_DAEMON_FACE_NULL_FACE_HPP

#include "face.hpp"

namespace nfd {

/**
 * \brief a Face that has no underlying transport and drops every packet
 */
class NullFace : public Face
{
public:
  explicit
  NullFace(const FaceUri& uri = FaceUri("null://"));

  void
  sendInterest(const Interest& interest) DECL_OVERRIDE;

  void
  sendData(const Data& data) DECL_OVERRIDE;

  void
  sendAnnouncement(const Announcement& announcement) DECL_OVERRIDE;

  void
  sendHint(const Hint& hint) DECL_OVERRIDE;

  void
  sendVicinity(const Vicinity& vicinity) DECL_OVERRIDE;

  void
  sendVicinityData(const VicinityData& vicinityData) DECL_OVERRIDE;

  void
  close() DECL_OVERRIDE;
};

} // namespace nfd

#endif // NFD_DAEMON_FACE_NULL_FACE_HPP
