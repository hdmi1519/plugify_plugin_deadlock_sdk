// Generated from dsdk.pplugin (group: worldtext)

export module dsdk.worldtext;
export import dsdk.enums;
export import dsdk.aliases;
export import dsdk.delegates;

import <cstdint>;
import <plg>;

#if defined(_WIN32)
#define PLUGIFY_EXPORT __declspec(dllexport)
#else
#define PLUGIFY_EXPORT __attribute__((visibility("default")))
#endif

export namespace dsdk {

  using _CreateWorldText = int64_t (*)(const plg::string&, float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
  PLUGIFY_EXPORT _CreateWorldText __dsdk_CreateWorldText = nullptr;
  /**
   * @brief Create 3D point_worldtext entity in the world
   * @param message (string)
   * @param x (float)
   * @param y (float)
   * @param z (float)
   * @param fontSize (float)
   * @param r (uint8)
   * @param g (uint8)
   * @param b (uint8)
   * @param a (uint8)
   * @return int64
   */

  int64_t CreateWorldText(const plg::string& message, float x, float y, float z, float fontSize, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return __dsdk_CreateWorldText(message, x, y, z, fontSize, r, g, b, a);
  }

  using _SetWorldTextMessage = void (*)(int64_t, const plg::string&);
  PLUGIFY_EXPORT _SetWorldTextMessage __dsdk_SetWorldTextMessage = nullptr;
  /**
   * @brief Update message text of CPointWorldText
   * @param worldText (int64)
   * @param text (string)
   */

  void SetWorldTextMessage(int64_t worldText, const plg::string& text) {
    return __dsdk_SetWorldTextMessage(worldText, text);
  }

} // namespace dsdk
