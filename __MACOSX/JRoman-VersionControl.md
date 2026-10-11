# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ COS119-L ]

- **[ Joel Roman ]**
- **[ 10/4/26]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [cls]: Clear the Screen
- [cd]: Print the "Working Directory"
- [ dir ]: List files and folders
- [ dir /a ]: List files and folders, including invisible files
- [ dir ]: List all files and folders, in human readable form
- [cd [folder_name]]: Change directory
- [cd \]: Change directory, go to root directory
- [cd %userprofile%]: Change directory and go to user home directory
- [cd ..]: Change directory, go up one folder level
- [cd ..\..]: Change directory, go up two folder levels
- [cd %userprofile%\Desktop]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ When I type cd followed by a space and the folder I dragged in, I get the file path to that folder.  ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Joel Roman 
- Local Version Control (LVCS) - In this approach, you use a simple database on your local machine to keep track of changes to files. Instead of copying files manually
- Centralized Version Control (CVCS) - To solve the collaboration issue, centralized systems introduced a single remote server that holds all versions of the project files. Developers "check out" files to work on them and "commit" their changes back directly to the server
- Distributed Version Control (DVCS) - This is the modern standard for software development. Instead of just checking out the latest snapshot of the files, developers use tools to **clone the entire codebase and its complete history** locally. If the central server crashes, any developer's local repository can be used to restore the project.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone < repository-url >]: Clone a repository
- [ git config --global user.name "Your Name" ]: Set-up a global user name
- [ git config --global user.email "your.email@example.com" ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add < file-name > ]: Add modified files to the next commit
- [ git commit -m "Your commit message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ To connect to GitHub from your Terminal using HTTPS, you can authenticate using either the modern GitHub CLI method or the traditional Personal Access Token (PAT) method. Because GitHub no longer accepts account passwords in the terminal, one of these authentication options is required ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [to explicitly tell Git which files and directories to ignore and leave out when tracking changes in a project]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [a hidden metadata file created automatically by macOS Finder to remember folder display settings like icon positions and window sizes]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [You should add environment configuration files to prevent private passwords, database URLs, and API keys from leaking into public or shared code repositories.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? I found the geekforgeeks site to provide really well presented diagrams and explanations to all of the concepts and definitions.]

**Terminal Commands**  
[Site Address](https://www.codecademy.com/article/command-line-commands)

**Three Types of Version Control**  
[Site Address](https://www.geeksforgeeks.org/git/version-control-systems/)

**Git Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Connecting to GitHub using Terminal**  
[Site Address](https://coderefinery.github.io/installation/ssh/)

**Using .gitignore and Why it's Important**  
[Site Address](https://github.com/orgs/community/discussions/165862)
