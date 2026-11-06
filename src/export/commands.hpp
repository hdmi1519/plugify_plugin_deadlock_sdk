#pragma once

#include <tier1/convar.h>
#include <string>

namespace dsdk {

bool DispatchCommand(int playerSlot, const CCommand &args);
bool DispatchChatCommand(int playerSlot, const std::string &chatText);

} // namespace dsdk
