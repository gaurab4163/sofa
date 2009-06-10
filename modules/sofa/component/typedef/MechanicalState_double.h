/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 beta 4      *
*                (c) 2006-2009 MGH, INRIA, USTL, UJF, CNRS                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                               SOFA :: Modules                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/



// File automatically generated by "generateTypedef"


#ifndef SOFA_TYPEDEF_MechanicalState_double_H
#define SOFA_TYPEDEF_MechanicalState_double_H

//Default files containing the declaration of the vector type
#include <sofa/defaulttype/VecTypes.h>
#include <sofa/defaulttype/RigidTypes.h>
#include <sofa/defaulttype/Mat.h>



#include <sofa/component/container/MechanicalObject.h>
#include <sofa/component/collision/RayModel.h>
#include <sofa/component/collision/SphereTreeModel.h>



//---------------------------------------------------------------------------------------------
//Typedef for MechanicalObject
typedef sofa::component::container::MechanicalObject<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<3, double>, sofa::defaulttype::Vec<3, double>, double> > MechanicalObject3d;
typedef sofa::component::container::MechanicalObject<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<2, double>, sofa::defaulttype::Vec<2, double>, double> > MechanicalObject1d;
typedef sofa::component::container::MechanicalObject<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<1, double>, sofa::defaulttype::Vec<1, double>, double> > MechanicalObject2d;
typedef sofa::component::container::MechanicalObject<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<6, double>, sofa::defaulttype::Vec<6, double>, double> > MechanicalObject6d;
typedef sofa::component::container::MechanicalObject<sofa::defaulttype::StdRigidTypes<3, double> > MechanicalObjectRigid3d;
typedef sofa::component::container::MechanicalObject<sofa::defaulttype::StdRigidTypes<2, double> > MechanicalObjectRigid2d;



//---------------------------------------------------------------------------------------------
//Typedef for RayModel
typedef sofa::component::collision::RayModel RayModel3d;



//---------------------------------------------------------------------------------------------
//Typedef for SphereTreeModel
typedef sofa::component::collision::SphereTreeModel SphereTreeModel3d;





#ifndef SOFA_FLOAT
typedef MechanicalObject3d MechanicalObject3;
typedef MechanicalObject1d MechanicalObject1;
typedef MechanicalObject2d MechanicalObject2;
typedef MechanicalObject6d MechanicalObject6;
typedef MechanicalObjectRigid3d MechanicalObjectRigid3;
typedef MechanicalObjectRigid2d MechanicalObjectRigid2;
typedef RayModel3d RayModel3;
typedef SphereTreeModel3d SphereTreeModel3;
#endif

#endif
