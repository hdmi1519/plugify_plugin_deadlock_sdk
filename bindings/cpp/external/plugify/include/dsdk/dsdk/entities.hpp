#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: entities)

namespace dsdk {

  using _CreateEntityByName = int64_t (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_CreateEntityByName __dsdk_CreateEntityByName;
namespace dsdk {
  /**
   * @brief Create entity instance by class name
   * @param className (string)
   * @return int64
   */
  inline int64_t CreateEntityByName(const plg::string& className) {
    return __dsdk_CreateEntityByName(className);
  }

  using _QueueSpawnEntity = void (*)(int64_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_QueueSpawnEntity __dsdk_QueueSpawnEntity;
namespace dsdk {
  /**
   * @brief Queue entity spawn with optional entity keyvalues
   * @param entity (int64)
   * @param ekv (int64)
   */
  inline void QueueSpawnEntity(int64_t entity, int64_t ekv) {
    return __dsdk_QueueSpawnEntity(entity, ekv);
  }

  using _ExecuteQueuedCreation = void (*)();
}
extern "C" PLUGIN_API dsdk::_ExecuteQueuedCreation __dsdk_ExecuteQueuedCreation;
namespace dsdk {
  /**
   * @brief Execute queued entity creation
   */
  inline void ExecuteQueuedCreation() {
    return __dsdk_ExecuteQueuedCreation();
  }

  using _RemoveEntity = void (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_RemoveEntity __dsdk_RemoveEntity;
namespace dsdk {
  /**
   * @brief Remove/destroy entity
   * @param entity (int64)
   */
  inline void RemoveEntity(int64_t entity) {
    return __dsdk_RemoveEntity(entity);
  }

  using _GetEntityByIndex = int64_t (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_GetEntityByIndex __dsdk_GetEntityByIndex;
namespace dsdk {
  /**
   * @brief Get entity pointer by index
   * @param index (int32)
   * @return int64
   */
  inline int64_t GetEntityByIndex(int32_t index) {
    return __dsdk_GetEntityByIndex(index);
  }

  using _GetEntityFromHandle = int64_t (*)(uint32_t);
}
extern "C" PLUGIN_API dsdk::_GetEntityFromHandle __dsdk_GetEntityFromHandle;
namespace dsdk {
  /**
   * @brief Resolve entity pointer from uint32 handle
   * @param handle (uint32)
   * @return int64
   */
  inline int64_t GetEntityFromHandle(uint32_t handle) {
    return __dsdk_GetEntityFromHandle(handle);
  }

  using _GetEntityHandle = uint32_t (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_GetEntityHandle __dsdk_GetEntityHandle;
namespace dsdk {
  /**
   * @brief Get handle of entity
   * @param entity (int64)
   * @return uint32
   */
  inline uint32_t GetEntityHandle(int64_t entity) {
    return __dsdk_GetEntityHandle(entity);
  }

  using _FindEntityByName = int64_t (*)(int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_FindEntityByName __dsdk_FindEntityByName;
namespace dsdk {
  /**
   * @brief Find entity by name
   * @param startEntity (int64)
   * @param name (string)
   * @return int64
   */
  inline int64_t FindEntityByName(int64_t startEntity, const plg::string& name) {
    return __dsdk_FindEntityByName(startEntity, name);
  }

  using _GetEntityDesignerName = plg::string (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_GetEntityDesignerName __dsdk_GetEntityDesignerName;
namespace dsdk {
  /**
   * @brief Get designer name of entity
   * @param entity (int64)
   * @return string
   */
  inline plg::string GetEntityDesignerName(int64_t entity) {
    return __dsdk_GetEntityDesignerName(entity);
  }

  using _GetEntityClassname = plg::string (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_GetEntityClassname __dsdk_GetEntityClassname;
namespace dsdk {
  /**
   * @brief Get class name of entity
   * @param entity (int64)
   * @return string
   */
  inline plg::string GetEntityClassname(int64_t entity) {
    return __dsdk_GetEntityClassname(entity);
  }

  using _Teleport = void (*)(int64_t, float, float, float, float, float, float, float, float, float);
}
extern "C" PLUGIN_API dsdk::_Teleport __dsdk_Teleport;
namespace dsdk {
  /**
   * @brief Teleport entity with position, angles and velocity
   * @param entity (int64)
   * @param posX (float)
   * @param posY (float)
   * @param posZ (float)
   * @param angPitch (float)
   * @param angYaw (float)
   * @param angRoll (float)
   * @param velX (float)
   * @param velY (float)
   * @param velZ (float)
   */
  inline void Teleport(int64_t entity, float posX, float posY, float posZ, float angPitch, float angYaw, float angRoll, float velX, float velY, float velZ) {
    return __dsdk_Teleport(entity, posX, posY, posZ, angPitch, angYaw, angRoll, velX, velY, velZ);
  }

  using _SetModel = void (*)(int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_SetModel __dsdk_SetModel;
namespace dsdk {
  /**
   * @brief Set visual model of entity
   * @param entity (int64)
   * @param modelName (string)
   */
  inline void SetModel(int64_t entity, const plg::string& modelName) {
    return __dsdk_SetModel(entity, modelName);
  }

  using _GetModelName = plg::string (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_GetModelName __dsdk_GetModelName;
namespace dsdk {
  /**
   * @brief Get model name of entity
   * @param entity (int64)
   * @return string
   */
  inline plg::string GetModelName(int64_t entity) {
    return __dsdk_GetModelName(entity);
  }

  using _SetScale = void (*)(int64_t, float);
}
extern "C" PLUGIN_API dsdk::_SetScale __dsdk_SetScale;
namespace dsdk {
  /**
   * @brief Set visual scale of entity
   * @param entity (int64)
   * @param scale (float)
   */
  inline void SetScale(int64_t entity, float scale) {
    return __dsdk_SetScale(entity, scale);
  }

  using _SetMoveType = void (*)(int64_t, uint8_t);
}
extern "C" PLUGIN_API dsdk::_SetMoveType __dsdk_SetMoveType;
namespace dsdk {
  /**
   * @brief Set entity move type
   * @param entity (int64)
   * @param moveType (uint8)
   */
  inline void SetMoveType(int64_t entity, uint8_t moveType) {
    return __dsdk_SetMoveType(entity, moveType);
  }

  using _SetGravityScale = void (*)(int64_t, float);
}
extern "C" PLUGIN_API dsdk::_SetGravityScale __dsdk_SetGravityScale;
namespace dsdk {
  /**
   * @brief Set entity gravity multiplier
   * @param entity (int64)
   * @param scale (float)
   */
  inline void SetGravityScale(int64_t entity, float scale) {
    return __dsdk_SetGravityScale(entity, scale);
  }

  using _EntityDerivesFrom = bool (*)(int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_EntityDerivesFrom __dsdk_EntityDerivesFrom;
namespace dsdk {
  /**
   * @brief Check if entity class derives from base class name
   * @param entity (int64)
   * @param baseClassName (string)
   * @return bool
   */
  inline bool EntityDerivesFrom(int64_t entity, const plg::string& baseClassName) {
    return __dsdk_EntityDerivesFrom(entity, baseClassName);
  }

} // namespace dsdk
