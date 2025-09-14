#
# @lc app=leetcode id=2225 lang=python3
#
# [2225] Find Players With Zero or One Losses
#

# @lc code=start
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        loser = defaultdict(int)
        players = set()
        for match in matches:
            players.add(match[0])
            players.add(match[1])
            loser[match[1]] += 1
        
        lose_0 = []
        lose_1 = []
        sorted_players = sorted(list(players))
        for player in sorted_players:
            if player not in loser:
                lose_0.append(player)
            elif loser[player] == 1:
                lose_1.append(player)
        return [lose_0, lose_1]
                    
# @lc code=end

