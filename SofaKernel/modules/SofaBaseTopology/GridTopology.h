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
#ifndef SOFA_COMPONENT_TOPOLOGY_GRIDTOPOLOGY_H
#define SOFA_COMPONENT_TOPOLOGY_GRIDTOPOLOGY_H
#include "config.h"

#include <SofaBaseTopology/MeshTopology.h>
#include <sofa/core/DataEngine.h>
namespace sofa
{

namespace component
{

namespace topology
{

/** Define a regular grid topology, with no spatial information.
  */
class SOFA_BASE_TOPOLOGY_API GridTopology : public MeshTopology
{
public:
    SOFA_CLASS(GridTopology,MeshTopology);
    typedef sofa::defaulttype::Vec3i Vec3i;
    typedef sofa::defaulttype::Vector2 Vector2;
    typedef sofa::defaulttype::Vector3 Vector3;
    typedef sofa::defaulttype::ResizableExtVector<Vector2> TextCoords2D;
    friend class GridUpdate;
private:
    class GridUpdate : public sofa::core::DataEngine
    {
    public:
        typedef MeshTopology::Edge Edge;
        typedef MeshTopology::Quad Quad;
        typedef MeshTopology::Hexa Hexa;
        SOFA_CLASS(GridUpdate,sofa::core::DataEngine);
        GridUpdate(GridTopology* t);
        void update();
    protected:
        void updateEdges();
        void updateQuads();
        void updateHexas();
    private:
        GridTopology* topology;
    };
protected:
    /// Default constructor
    GridTopology();
    /// Constructor with grid size by int
    GridTopology(int nx, int ny, int nz);
    /// Constructor with grid size by Vec3
    GridTopology(Vec3i nXnYnZ );

    /// Internal method to set the number of point using grid resolution. Will call \sa MeshTopology::setNbPoints
    virtual void setNbGridPoints();

    /// Method to create grid texture coordinates, should be overwritten by children
    virtual void createTexCoords(){}
    /// Method to compute Hexa list, called if \sa d_computeHexaList is true at init. Should be overwritten by children.
    virtual void computeHexaList();
    /// Method to compute Quad list, called if \sa d_computeQuadList is true at init. Should be overwritten by children.
    virtual void computeQuadList();
    /// Method to compute Edge list, called if \sa d_computeEdgeList is true at init. Should be overwritten by children.
    virtual void computeEdgeList();
    /// Method to compute Point list, called if \sa d_computePointList is true at init. Should be overwritten by children.
    virtual void computePointList();

public:
    /// BaseObject method should be overwritten by children
    virtual void init();

    /// BaseObject method should be overwritten by children
    virtual void reinit(){}


    /** \brief Set grid resolution in the 3 directions
     * @param nx x resolution
     * @param ny y resolution
     * @param nz z resolution
     * */
    void setSize(int nx, int ny, int nz);

    /** \brief Set grid resolution in the 3 directions, similar to \sa setSize(int nx, int ny, int nz)
     * @param Vec3i nXnYnZ resolution in 3D
     * */
    void setSize( Vec3i nXnYnZ );

    /// Set grid X resolution, @param value
    void setNx(int value) { (*d_n.beginEdit())[0] = value; setNbGridPoints(); }
    /// Set grid Y resolution, @param value
    void setNy(int value) { (*d_n.beginEdit())[1] = value; setNbGridPoints(); }
    /// Set grid Z resolution, @param value
    void setNz(int value) { (*d_n.beginEdit())[2] = value; setNbGridPoints(); }

    /// Get X grid resolution, @return int
    int getNx() const { return d_n.getValue()[0]; }
    /// Get Y grid resolution, @return int
    int getNy() const { return d_n.getValue()[1]; }
    /// Get Z grid resolution, @return int
    int getNz() const { return d_n.getValue()[2]; }

    /// Get the one-dimensional index of a grid point given its @param i @param j @param k indices
    unsigned getIndex( int i, int j, int k ) const;

    /// Overwrite from @sa MeshTopology::hasPos always @return bool true
    bool hasPos()  const { return true; }

    /// Get Point in grid @return Vector3 given its @param id i. Will call @sa getPointInGrid. This method should be overwritten by children.
    virtual Vector3 getPoint(int i) const;

    /// Get Point in grid @return Vector3 given its position in grid @param i, @param j, @param k
    virtual Vector3 getPointInGrid(int i, int j, int k) const;

    /// get X from Point index @param i, will call @sa getPoint
    SReal getPX(int i)  const { return getPoint(i)[0]; }
    /// get Y from Point index @param i, will call @sa getPoint
    SReal getPY(int i) const { return getPoint(i)[1]; }
    /// get Z from Point index @param i, will call @sa getPoint
    SReal getPZ(int i) const { return getPoint(i)[2]; }


    void parse(core::objectmodel::BaseObjectDescription* arg)
    {
        this->MeshTopology::parse(arg);

        if (arg->getAttribute("nx")!=NULL && arg->getAttribute("ny")!=NULL && arg->getAttribute("nz")!=NULL )
        {
            const char* nx = arg->getAttribute("nx");
            const char* ny = arg->getAttribute("ny");
            const char* nz = arg->getAttribute("nz");
            d_n.setValue(Vec3i(atoi(nx),atoi(ny),atoi(nz)));
        }

        this->setNbGridPoints();
    }


    virtual int getNbHexahedra() { return (d_n.getValue()[0]-1)*(d_n.getValue()[1]-1)*(d_n.getValue()[2]-1); }


    Hexa getHexaCopy(int i);
    using MeshTopology::getHexahedron;
    Hexa getHexahedron(int x, int y, int z);

#ifndef SOFA_NEW_HEXA
    Cube getCubeCopy(int i) { return getHexaCopy(i); }
    Cube getCube(int x, int y, int z) { return getHexahedron(x,y,z); }
#endif

    Quad getQuadCopy(int i);
    using MeshTopology::getQuad;
    Quad getQuad(int x, int y, int z);

    int point(int x, int y, int z) const { return x+d_n.getValue()[0]*(y+d_n.getValue()[1]*z); }
    int hexa(int x, int y, int z) const { return x+(d_n.getValue()[0]-1)*(y+(d_n.getValue()[1]-1)*z); }
    int cube(int x, int y, int z) const { return hexa(x,y,z); }

protected:
    /// Data storing the size of the grid in the 3 directions
    Data<Vec3i> d_n;

    /// Data bool to set option to compute topological elements
    Data<bool> d_computeHexaList, d_computeQuadList, d_computeEdgeList, d_computePointList;
    /// Data bool to set option to compute texcoords
    Data<bool> d_createTexCoords;
};

} // namespace topology

} // namespace component

} // namespace sofa

#endif
