# cc3k
Dungeon-crawler game for University of Waterloo CS246 Course

Programmed and designed by Junwen Jiang, Joshua Du, Jonathan Poon, using C++.

Developed in the span of two weeks for a final group assignment project.

Controls:

• no,so,ea,we,ne,nw,se,sw: moves the player character one block in the appropriate cardinal direction
• u <direction>: uses the potion indicated by the direction (e.g. no, so, ea)
• a <direction>: attacks the enemy in the specified direction, if the monster is in the immediately
specified block (e.g. must be one block north of the @)
• h, e, d, o: specifies the race the player wishes to be when starting a game
• r: restarts the game. All stats, inventory, and gold are reset. A new race should be selected.
• q: allows the player to admit defeat and exit the game.

Positive Potions:
• Restore health (RH): restore up to 10 HP (cannot exceed maximum prescribed by race)
• Boost Atk (BA): increase ATK by 5
• Boost Def (BD): increase Def by 5
Negative Potions:
• Poison health (PH): lose up to 10 HP (cannot fall below 0 HP)
• Wound Atk (WA): decrease Atk by 5
• Wound Def (WD): decrease Def by 5
