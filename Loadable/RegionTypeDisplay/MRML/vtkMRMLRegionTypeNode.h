/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLAirwayNode.h,v $
  Date:      $Date: 2006/03/19 17:12:28 $
  Version:   $Revision: 1.6 $

=========================================================================auto=*/
///  vtkMRMLAirwayNode - MRML node to represent a fiber bundle from tractography in DTI data.
///
/// RegionType nodes contain general convetions for the extraction of specified regions types from a LabelMap.
/// A Airway node contains many fibers and forms the smallest logical unit of tractography
/// that MRML will manage/read/write. Each fiber has accompanying tensor data.
/// Visualization parameters for these nodes are controlled by the vtkMRMLRegionTypeNode class.
//

#ifndef __vtkMRMLRegionTypeNode_h
#define __vtkMRMLRegionTypeNode_h

#include "vtkMRMLScalarVolumeNode.h"
#include "vtkSlicerRegionTypeModuleMRMLExport.h"

// STD includes
#include <vector>
#include <list>
#include <string>

class vtkMRMLStorageNode;
class vtkMRMLColorNode;
class vtkMRMLRegionTypeDisplayNode;

class VTK_SLICER_REGIONTYPE_MODULE_MRML_EXPORT vtkMRMLRegionTypeNode : public vtkMRMLScalarVolumeNode
{
public:
  static vtkMRMLRegionTypeNode *New();
  vtkTypeMacro(vtkMRMLRegionTypeNode,vtkMRMLScalarVolumeNode);
  void PrintSelf(ostream& os, vtkIndent indent);

  //--------------------------------------------------------------------------
  /// MRMLNode methods
  //--------------------------------------------------------------------------

  virtual vtkMRMLNode* CreateNodeInstance();

  ///
  /// Get node XML tag name (like Volume, Model)
  virtual const char* GetNodeTagName() {return "RegionType";};

  vtkMRMLRegionTypeDisplayNode* GetRegionTypeDisplayNode();

  virtual void ProcessMRMLEvents ( vtkObject * /*caller*/,
                                   unsigned long /*event*/,
                                   void * /*callData*/ );

  std::vector<unsigned char> &  GetAvailableRegions()
  {
    return AvailableRegions;
  }

  std::vector<unsigned char> &  GetAvailableTypes()
  {
    return AvailableTypes;
  }

  std::vector<std::string>&  GetAvailableRegionNames()
  {
    return AvailableRegionNames;
  }

  std::vector<std::string>&  GetAvailableTypeNames()
  {
    return AvailableTypeNames;
  }

  unsigned char GetChestRegionFromValue(unsigned short value)
  {
    return value - ((value >> 8) << 8);
  }

  unsigned char GetChestTypeFromValue(unsigned short value)
  {
    return (value >> 8);
  }

  void UpdateAvailableRegionsAndTypes();

protected:
  vtkMRMLRegionTypeNode();
  virtual ~vtkMRMLRegionTypeNode();
  vtkMRMLRegionTypeNode(const vtkMRMLRegionTypeNode&);
  void operator=(const vtkMRMLRegionTypeNode&);

  std::vector<unsigned char> AvailableRegions;
  std::vector<unsigned char> AvailableTypes;

  std::vector<std::string> AvailableRegionNames;
  std::vector<std::string> AvailableTypeNames;
};

#endif