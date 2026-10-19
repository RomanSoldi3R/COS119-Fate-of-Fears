COS119-L
Joel Roman
10/11/2026

<br>

# Project & Portfolio 1

### Student First & Last Name

Hello my name is [Joel Roman]. I am a student from [Worcester, MA]. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1
⚙️ Overview - What I worked on this past week
<br>What I worked on this past week was a bunch of classes, and a little bit of the main menu to have something playable. I started by creating the classes and what each class would do. The character class shares the name, health and attack power with heroes and enemies. Then each hero class has a take damage and take turn specific to them but made those methods virtual so each class has something different.  I also added a destructor for future use which could come in handy for when I want to delete a hero pointer when creating my heroes in the main.  I have also completed my knight class which is inherited from the hero class and has a stamina variable so I could do unique things with that such as blocking and regen. Lastly I made a starting menu with ascii art to make things pop and a menu function header to plan with future menu functions just in case.

🌵 Challenges - What problems did I have & how I'm addressing them
<br>What I've struggled with the most is trying to wrap my head around the structure of the game and what I could need with future programming in mind. 

🏆 Accomplishments - What is something I "leveled up" on this week
<br>what I leveled up on this week was the use of virtual methods which proved to be really useful in my project dealing with multiple classes. I also researched a way to implement an enter/esc function instead of a switch using _ getch() to better fit my vision for the game and am getting better with C++ syntax involving this but I know this will be a constant struggle.

🔮 Next Steps - What I plan to prioritize and do next

What I plan to do next is implement an enemy class, ascii art for the knight and sorcerer, also change up the menu so I have a campaign built in to start an adventure instead of just choose hero then battle but we shall see.
### Week 2
⚙️ Overview - What I worked on this past week
<br>What I have worked on this week was my Battle Sequence which I used a namespace to do so. I Have completed an Ability Class to hold a vector of hero abilities which I thought of when creating the Sorceress Class to hold her book of spells.

🌵 Challenges - What problems did I have & how I'm addressing them
<br>I ran into a few challenges. A lot of them stem from my project just growing. There's a wall of text and especially now, I have to make sure everything is readable which forced me improve on my coding readability skills throughout the week. Which then lead to creating functions such as "erase previous lines" in my helper that take in an int so I wont have to repeat code and stops the console from printing continuously without removing the previous lines.

🏆 Accomplishments - What is something I "leveled up" on this week
<br>What I leveled up this week was with vectors. I have coded using vectors before but now I had to understand WHY I needed to code using vectors. I loved working on my project this week for that reason alone. I used vectors for my Sorceress' Spell book as well as Skills for my Knight. Then after creating my Ability Class, I was able to create a vector of abilities which then I initialized them to each respective class so they start with those abilities. This way any spell or skill they find in the future can be added to that vector. I didn't know how to do this before and got me excited to complete my next steps.

🔮 Next Steps - What I plan to prioritize and do next

Next I plan to implement the Castle/dungeon exploration and opening dialog. That makes it so when the character picks a class, they can then explore rooms, fight enemies and find secrets.
### Week 3

- ⚙️ **Overview** – What did you work on this past week?
    This past week I have worked on so much compared to any other week. I have completed my Room Label namespace which I renamed Pathway enums so it made more sense to me. the Pathway Class which held a direction and a room label. A Room Class which held a room name and a vector of pathways. The castle class which created my castle and held a floorplan which that held a vector of rooms in order to create the castle. I created a has visited, in view, and a move method which drew the view of the rooms and made it so the player can move from room to room. I worked on a menu namespace to hold all of my menus. I added a flee option and finally caught up on some art for the game.  
    
- 🛠️ **Improvements** – What changes, refinements, or new features did you make?
    I made a ton of improvements this week. I added a menu namespace to hold all my menus past, present and future so a lot of reorganizing. I made it so you can now access the options menu and control menu in the game. I added a flee option so that you have a chance to run if you don't want to fight. After getting the navigation completed, I reworked all the menus to with some color and better placement to help with readability.
    
- 🌵 **Challenges** – What obstacles did you encounter, and how are you addressing them?
    Obstacles I've encountered were mostly from creating the navigation system. There's a lot I have learned with vectors this week that I'm surprised I forgot such as .pop back, or .back which were really helpful to look at the last spot in the vector. I had a good time just getting practice in with vectors within vectors and enums which I don't use enough. I addressed these issues by constantly researching and asking questions about how I can better understand what I had written so far because I was constantly forgetting what my pathway constructor held when it was in my room constructor and then that room constructor was in a vector called floorplan in my castle. I'm only now getting understanding it but there was a lot of looking back and forth going on.
    
- 💬 **Feedback** – What feedback have you received, and how will it influence your next steps?
    I have received feedback about controls and potential improvements. I did end up adding the options and controls menu. I was thinking of adding a beastiary but I'm still unsure. As well as a suggestion for an inventory, that might make it considering I'm already thinking about a loot system.
    
- 🔮 **Next Steps** – What is your primary goal for Week 4?
	My primary goal is to add the loot system and final boss. With those implemented, The game would be complete and ready for player testing.
### Week 4

My final stand up...
