/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, development version     *
*                (c) 2006-2017 INRIA, USTL, UJF, CNRS, MGH                    *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#ifndef SOFA_COMPONENT_TOPOLOGY_CYLINDERGRIDTOPOLOGY_H
#define SOFA_COMPONENT_TOPOLOGY_CYLINDERGRIDTOPOLOGY_H
#include "config.h"

#include <SofaBaseTopology/GridTopology.h>
#include <sofa/defaulttype/Vec.h>

namespace sofa
{

namespace component
{

namespace topology
{

class SOFA_GENERAL_TOPOLOGY_API CylinderGridTopology : public GridTopology
{
public:
    SOFA_CLASS(CylinderGridTopology,GridTopology);
    typedef sofa::defaulttype::Vector3 Vector3;
protected:
    CylinderGridTopology(int nx, int ny, int nz);
    CylinderGridTopology();
public:
    /** \brief Overload method of @sa GridTopology::getPointInGrid.
     * Get Point in grid @return Vector3 given its position in grid @param i, @param j, @param k
     * */
    Vector3 getPointInGrid(int i, int j, int k) const;

    void setCenter(SReal x, SReal y, SReal z);
    void setAxis(SReal x, SReal y, SReal z);
    void setRadius(SReal radius);
    void setLength(SReal length);

protected:
    Data< Vector3 > d_center;
    Data< Vector3 > d_axis;
    Data< SReal > d_radius, d_length;
};

} // namespace topology

} // namespace component

} // namespace sofa

#endif
