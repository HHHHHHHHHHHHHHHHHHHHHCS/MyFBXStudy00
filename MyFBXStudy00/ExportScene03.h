#pragma once

#include <fbxsdk.h>

#include "Common.h"
#include "MyKFbxMesh.h"

#define SAMPLE_FILENAME_MC		"ExportScene03_MC.fbx"
#define SAMPLE_FILENAME_PC2		"ExportScene03_PC2.fbx"
#define SAMPLE_CACHE_TYPE		2

#define PID_MY_GEOMETRY_LEMENT	0

class ExportScene03
{
public:

	 int DoMain(int argc, char** argv);
	
	// Function prototypes.
	bool CreateScene(FbxScene* pScene, char* pSampleFileName);

	FbxNode* CreateCubeWithTexture(FbxScene* pScene, const char* pName);
	FbxNode* CreatePyramidWithMaterials(FbxScene* pScene, const char* pName);
	FbxNode* CreateTriangle(FbxScene* pScene, const char* pName);
	FbxNode* CreateCubeWithMaterialAndMyKFbxMesh(FbxScene* pScene, const char* pName);

	void CreateTexture(FbxScene* pScene, FbxMesh* pMesh);
	void CreateMaterials(FbxScene* pScene, FbxMesh* pMesh);
	void CreateMaterialsWithMyKFbxMesh(FbxScene* pScene, MyKFbxMesh* pMyKFbxMesh);

	void MapShapeOnPyramid(FbxScene* pScene, FbxNode* pPyramid);
	void MapVertexCacheOnTriangle(FbxScene* pScene, FbxNode* pTriangle, char* pSampleFileName);

	void SetCubeDefaultPosition(FbxNode* pCube);
	void SetPyramidDefaultPosition(FbxNode* pPyramid);
	void SetTriangleDefaultPosition(FbxNode* pTriangle);
	void SetMyKFbxMeshCubeDefaultPosition(FbxNode* pMyKFbxCube);

	void Animate(FbxNode* pNode, FbxAnimLayer* pAnimLayer);
	void AnimateVertexCacheOnTriangleDoubleVertex(FbxNode* pNode, double pFrameRate);
	void AnimateVertexCacheOnTriangleInt32(FbxNode* pNode, double pFrameRate);
	void AnimateVertexCacheOnTriangleFloat(FbxNode* pNode, double pFrameRate);

	bool gExportVertexCacheMCFormat = true;

	// Declare the UV names globally so we can create them on the mesh and then assign them properly
	// to our textures when we create them
	static const char* gDiffuseElementName; 
	static const char* gAmbientElementName; 
	static const char* gEmissiveElementName;

	// gCacheType == 0 (default)  - double vertex array
	//            == 1            - int32 array
	//            == 2            - float array
	int gCacheType = -1;
};
