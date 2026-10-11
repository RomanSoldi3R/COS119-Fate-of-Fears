
---
## 📌 Project Overview

**Project Name:**
→ Fate of Fears
  
**What does your program currently do? (1–3 sentences)**   
→ My Program currently displays the Title Screen --> Class Selection --> Knight/Sorceress --> Battle Sequence --> Win/Lose Screen --> Loops back to Title Screen

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   Right now I have the Main Menu, Knight and Sorceress Classes, as well as the Battle Sequence complete. After you win or lose, you are shown a win/lose screen and are returned to the main menu.
  
**What is NOT working or incomplete?**   
→   What's not working is the castle/dungeon exploration. I have only started that process with a few comments in place. Also the art and new abilities will be an on going task until the game is finally complete, as well as the combat loop and balance. I have a general idea but more testing is needed. 
  
**What feels confusing or messy in your code?**   
→ What feels messy is the Knight and Sorceress Classes but only because there is so much more to them. I have it so everyone has a chance to miss, crit and each hit depending on the condition has a different flavor text.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Castle exploration
  
**What does this feature do?**   
→   Castle exploration is the process of going from room to room using dialog options and art to point you towards possible secrets, items, enemies and the final Boss.
  
**Why is this feature important?**   
→   This feature is important because it opens up the game from being a combat simulator to an actual adventure.
  
---
### Feature 2  
**Name:**   
→   Item and skill acquisition.
  
**What does this feature do?**   
→   Given the castle exploration explanation, this feature will allow the hero to find secrets and collect items and skills to power them up in order to fight the final boss.
  
**Why is this feature important?**   
→   This feature is important because it expands on the idea of adventure and makes it much more fun and worth it to explore before fighting the final boss.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   
  
**What does this feature do?**   
→   
  
**Why is this feature important?**   
→   
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   I do find it hard to think ahead until I'm at the moment when I need something added. All I can think of right now is the Castle Exploration class which will handle the choice selection for the upcoming rooms and a possible navigation method.  
  
**Will you modify any existing classes? How?**   
→   Yes, The hero's will get new abilities and items to find in their adventure. I will be doing that by adding any ability found within the exploration portion to the players list of abilities using a vector.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   I will be using a vectors to add to their arsenal and pointers to keep track on the hero as they move around the castle.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   Main Menu
2. User chooses →   Start Game/Exit
3. Program responds →   Select Class: Knight/Sorceress  
4. Loop/next step →   Combat Sequence vs Goblin
5. Loop/next step →   Return to Main Menu

---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   I have added the pause function last week which helps. This week I added a win/lose screen and I will continue to iterate as I add more art and dialog to the game. I like adding color so I will continue to do that to help make things stand out as well and make things more readable.
  
- Better error handling:   
→   I usually go to my error list immediately, then go to the line the error is at and either look it up using the code provided or try to research it on my own. Through my research I have landed on different ways to code to help to protect against errors in the first place and will plan to continue studying to get better at programming. When to use the new code or the ones I've originally learned will be the challenge such as using a try catch with a string response for a text input vs one key press using _getch().
  
- Improved menu/navigation:   
→   I will continue to iterate on this throughout but I might add a legend in the main menu showing the controls and maybe other information.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   using pointers. I didn't use them much in the ability class or battle sequence but I will need to use them in the castle exploration portion.
  
**What is your plan if you get stuck?**   
→   I tend to reference school projects, use google or utilize Ai to help me better understand a concept so I plan to continue with that approach. Once understood then I program one small step at a time until I can comment on what I've done so that it makes sense to me.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   Pointers because as stated in my challenges I think this is something I don't fully understand yet but will continue to try my best.
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   Practice, practice, practice. Experimentation then more practice and research.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   Castle/Pathways Class
- [ ]   Key Legend
- [ ]   Art (for every asset)
- [ ]   Map (maybe)
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> I'm very excited to get into the castle exploration this week. I plan to add the method for handling the pathways and maybe holding onto that memory for the possible map. Adding the art for the assets that are already complete. Then running a hero though the pathways to decide whether I want them to be random or with a map to so you can backtrack. After that is complete I will add a way to acquire new items and abilities to the game so the player can find more power along the journey. Finally I will test, test, test.