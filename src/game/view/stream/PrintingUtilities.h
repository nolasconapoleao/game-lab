#include <string_view>

namespace view {
namespace foreground {
constexpr std::string_view Default = "\e[39m";
constexpr std::string_view Black = "\e[30m";
constexpr std::string_view Red = "\e[31m";
constexpr std::string_view Green = "\e[32m";
constexpr std::string_view Yellow = "\e[33m";
constexpr std::string_view Blue = "\e[34m";
constexpr std::string_view Magenta = "\e[35m";
constexpr std::string_view Cyan = "\e[36m";
constexpr std::string_view LightGray = "\e[37m";

constexpr std::string_view DarkGray = "\e[90m";
constexpr std::string_view LightRed = "\e[91m";
constexpr std::string_view LightGreen = "\e[92m";
constexpr std::string_view LightYellow = "\e[93m";
constexpr std::string_view LightBlue = "\e[94m";
constexpr std::string_view LightMagenta = "\e[95m";
constexpr std::string_view LightCyan = "\e[96m";
constexpr std::string_view White = "\e[97m";
} // namespace foreground

namespace background {
constexpr std::string_view Default = "\e[49m";
constexpr std::string_view Black = "\e[40m";
constexpr std::string_view Red = "\e[41m";
constexpr std::string_view Green = "\e[42m";
constexpr std::string_view Yellow = "\e[43m";
constexpr std::string_view Blue = "\e[44m";
constexpr std::string_view Magenta = "\e[45m";
constexpr std::string_view Cyan = "\e[46m";
constexpr std::string_view LightGray = "\e[47m";

constexpr std::string_view DarkGray = "\e[100m";
constexpr std::string_view LightRed = "\e[101m";
constexpr std::string_view LightGreen = "\e[102m";
constexpr std::string_view LightYellow = "\e[103m";
constexpr std::string_view LightBlue = "\e[104m";
constexpr std::string_view LightMagenta = "\e[105m";
constexpr std::string_view LightCyan = "\e[106m";
constexpr std::string_view White = "\e[107m";
} // namespace background

namespace effect {
constexpr std::string_view Reset = "\e[0m";
constexpr std::string_view Bold = "\e[1m";
constexpr std::string_view Dim = "\e[2m";
constexpr std::string_view UnderLine = "\e[4m";
constexpr std::string_view Blink = "\e[5m";
constexpr std::string_view Invert = "\e[7m";
constexpr std::string_view Hidden = "\e[8m";
} // namespace effect

namespace reset {
constexpr std::string_view ResetAllAttributes = "\e[0m";
constexpr std::string_view ResetBoldOrBright = "\e[21m";
constexpr std::string_view ResetDim = "\e[22m";
constexpr std::string_view ResetUnderlined = "\e[24m";
constexpr std::string_view ResetBlink = "\e[25m";
constexpr std::string_view ResetReverse = "\e[27m";
constexpr std::string_view ResetHidden = "\e[28m";
} // namespace reset

} // namespace view
