#pragma once

#include <memory>
#include <unordered_map>

namespace unirender {
enum UniRenderStatus { OK, FAILED };

enum UniRenderType { SOFT_PATH_TRACING, OPTIX_PATH_TRACING };

union Float3 {
  float di[3];
  struct {
    float x, y, z;
  } dv;
};

union Float2 {
  float di[2];
  struct {
    float x, y;
  } dv;
};

union Int3 {
  float di[3];
  struct {
    int x, y, z;
  } dv;
};

union Int2 {
  float di[2];
  struct {
    int x, y;
  } dv;
};

using ID = size_t;

struct MeshData {
  int vertexNum{0};
  Float3 *positions{nullptr};
  Float3 *normals{nullptr};
  Float2 *uvs{nullptr};

  int facetNum{0};
  Int3 *positionIndices{nullptr};
  Int3 *normalIndices{nullptr};
  Int3 *uvIndices{nullptr};

  int matNum{0};
  ID *matIds{nullptr};
};

enum MaterialType { MAT_PBR, MAT_BLINN };

struct MaterialData {
  MaterialData(MaterialType _type) : type(_type) {}
  MaterialType type;
};

struct BlinnMaterialData : public MaterialData {
  BlinnMaterialData() : MaterialData(MAT_BLINN) {}

  Float3 kd;
  Float3 ks;

  bool emit{false};
  Float3 emission;
};

struct LightData {};

struct RadianceData {};

enum PictureFormat { PIC_RGB, PIC_BGR };

struct Camera {
  Float3 position;
  Float3 forward;
  Float3 up;

  int w{1920};
  int h{1080};
  PictureFormat picFormat{PIC_RGB};
  int bit{8};
  float fov{39.6};  // degree
  float near{0.1};  // m
  float far{100};   // m

  void *pic{nullptr};
};

class UniRender {
 public:
  static UniRender *CreateRender(UniRenderType type = SOFT_PATH_TRACING);

  virtual int Init() = 0;

  virtual int AddMesh(MeshData *meshData, ID &meshId) = 0;

  virtual int AddMaterial(MaterialData *materialData, ID &materialId) = 0;

  virtual int AddLight(LightData *lightData, ID &lightId) = 0;

  virtual int AddRadianceMap(RadianceData *radianceData, ID &radianceId) = 0;

  virtual int Remove(ID id) = 0;

  virtual int Clear() = 0;

  virtual int CommitScene() = 0;

  virtual int Render(Camera *cam) = 0;
};

}  // namespace unirender