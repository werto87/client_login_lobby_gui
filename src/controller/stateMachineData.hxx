#ifndef B6D64EAB_CF55_4504_9D9D_098D831157E9
#define B6D64EAB_CF55_4504_9D9D_098D831157E9
#include <chrono>
#include <deque>
#include <game_01_shared_class/serialization.hxx>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <variant>
#include <vector>

struct ChatData
{
  std::string selectChannelComboBoxName ();

  std::vector<std::string> const &messagesForChannel (std::string const &channel);

  std::vector<std::string> channelNames ();

  std::optional<std::string> selectedChannelName;
  std::string channelToJoin;
  std::string messageToSendToChannel;
  std::map<std::string, std::vector<std::string>> channelMessages{};
  bool joinChannelClicked = false;
  bool sendMessageClicked = false;
};

struct Button
{
  std::string name{};
  bool pressed = false;
  bool disabled = false;
  auto operator<=> (Button const &) const = default;
};

typedef std::variant<std::monostate, shared_class::CreateGameLobbyError, shared_class::JoinGameLobbyError, shared_class::LoginAccountError, shared_class::WantToRelog, shared_class::CreateAccountError, shared_class::SetMaxUserSizeInCreateGameLobbyError> MessageBoxEvent;
struct MessageBoxPopup
{
  MessageBoxEvent event{};
  std::string message{};
  std::vector<Button> buttons{};
};

struct MakeGameMachineData
{
  ChatData chatData{};
  std::string accountName{};
};

struct WaitForServer
{
  using timer = std::chrono::system_clock;

  timer::duration
  elapsedTime () const
  {
    return timer::now () - clock_wait;
  }
  timer::time_point clock_wait;
  std::vector<Button> buttons{};
};

struct MessagesToSendToServer
{
  std::deque<std::string> messagesToSendToServer{};
};

#endif /* B6D64EAB_CF55_4504_9D9D_098D831157E9 */
