#include "User.h"

namespace users_correct {
// Pretend there's some complex database stuff going on here.
UserScoreRecord GetUserScore(size_t userId)
{
    return UserScoreRecord {
        .userName = "Bob",
        .score = userId * 77
    };
}
}

namespace users_incorrect {
// Pretend there's some complex database stuff going on here.
std::pair<std::string, size_t> GetUserScore(size_t userId)
{
    return { "Bob", userId * 77 };
}
}
