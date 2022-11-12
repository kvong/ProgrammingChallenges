# Hockey Rivalry

A dynamic programming problem where the solution requires a two-dimensional array.

## The Problem

The Geese played *n* games, each of which had one of two outcomes: a win for the Geese (W) or a loss for the Geese (L). There are no tie games. For each of their games, we know whether they won or lost, and we know the number of goals that they scored. For example, we might know that their first game was a win (W) and they scored four goals in that game. (Their opponent must therefore have scored fewer than four goals.) The Hawks also played *n* games and, the same as the Geese, each game was a win or loss for the Hawks. Again for each of their games, we know whether they won or lost, and we know the number of goals that they scored.
    Some of the games that these teams played may have been against each other, but there are other teams, too, and some of the games may have been against these other teams.
    We ahve no information about who played whom. We might know that the Geese won a certian game and that they scored four goals in that game, but we don't know who their opponent was - their opponent could have been the Hawks but also could have been some other team.
    A *rivalry* game is where the Geese played the Hawks.
    Our task is to determine the maximum number of goals that could have been scored in rivalry games.
    
## Input
The input contains one test case, the information for which spread over five lines as follow:
- The first line contains n, the number of games that each team played. *n* is between 1 and 1,000.
- The second line contains a string of length *n*, where each character is a W (win) or L (loss). this line tells us the outcome of each game played by the Geese. For example, WLL means that the Geese won their fest game, lost their second game, and lost their third game.
- The third line contains *n* integers, giving the number of goals scored in each games by the Geese. For example, 4 1 2 means that the Geese scored four goals in their first game, one goal in their second game, and two goals in their third game.
- The fourth line is like the second and tells us the outcome of each game for the Hawks.
- The fifth line is like the third and tells us the number of goals scored in each game by the Hawks.
```
3
WWW
2 5 1
WLL
4 4 4
```

## Output
The output is a single integer: maximum number of goals scored in possible rivalry games.
    
