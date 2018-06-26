# _release
ECE 220, Summer 2018 Release Repository

Welcome to ECE220! This repository contains all the lab assignments, machine
problems, and exams that will be completed during the course.  The following
sections list some Git resources, explain the organization of this repository,
how to retrieve/submit assignments, and how to view your grades.

More information about the course can be found at the [course wiki][1]

## Git resources

This course uses Git and Github as the primary means of distributing materials.
If you are unfamiliar with git, please take a look at the links below to learn
more about Git and its workflow:
* [Interactive Git tutorial][2]
* [Git cheatsheet][3]
* [Git transport commands and workflow][4]
* [Pro Git online book][5]

The above list is only a very small fraction of the Git resources that are
available online. We encourage you to research other resources as well.

## Organization

The `_release` repository contains all lab assignments, machine problems,
and exams for the course. Each individual assignment will be released under its
own branch at an appropriate time. All available branches can be viewed by
selecting on the drop-down labeled `Branch: home-page`.

## Retreiving and submitting assignments

### First time set-up

Please follow the steps below to set up a repository with ECE220 and to be able
retrieve/submit assignments.

To create a repository for the class, visit
<https://edu.cs.illinois.edu/ghe/createRepo/ece220/> and a repository will be
created for you automatically. If you navigate to
<https://github-dev.cs.illinois.edu/ECE220SU18>, you will see a repository under
your NetID. Click on your NetID and you will be taken to a page that shows the
contents of your repository.

On the upper-left side of the page, there is a button **Clone or download**.
Click on the button and make sure it says **Clone with HTTPS**. If not, click on
the **Use HTTPS** text. Copy the link shown in the window which should be of the
form <https://github-dev.cs.illinois.edu/ECE220SU18/NetID.git>. In a terminal,
navigate to the location where you would like to keep your files for ECE220.
Type and paste the copied URL:

```
git clone https://github-dev.cs.illinois.edu/ECE220SU18/NetID.git
```

This will clone the remote repository to your computer where you will be able to
retrieve/submit/work on assignments. To be able to retrieve assignments from the
`_release` repository you have to add it as a remote:

```
cd NetID
git remote add release https://github-dev.cs.illinois.edu/ECE220SU18/_release.git
```

You can check whether the remote was added:

```
git remote -v
```

Set your user name and email with:

```
git config user.name "Your Name"
git config user.email "NetID@illinois.ed"
```

Verify that your name and email have been correctly set:

```
git config --local --list
```

It is important that this configuration information is correct because it is
used by the grading script to get the correct revision of your submissions for
grading. If this information is not set according to the above guidelines, your
assignments may be graded incorrectly.


### Retrieve assignments

To retrieve (or update) released assignments, run:

```
git fetch release
git merge release/<assignment> -m "<some comment>"
git push origin master
``` 

where `<assignment>` is a branch name corresponding to a particular assignment
and `<some comment>` is a comment of your choice. The last command pushes the
newly merged files to your remote repository. If something ever happens to your
repository and you need to go back in time, you will be able to revert your
repository to when you first retrieved an assignment.


### Submit assignments

To submit (or update) completed assignments, familiarize yourself with the
process below.

There are a couple of states that files may be in as you are working on your
assignment:
* unmodified tracked - files that are part of the local repository and have
  not had any changes made to them.
* modified tracked - files that are part of the local repository but have
  been changed.
* untracked - files that originally were not part of the local repository but
  have been created and are part of the workspace now.
All the files that are pulled/merged into your local repository are already
tracked.

To see all modified tracked and untracked files in your Git workspace, run:

```
git status
```

To stage any modified tracked or untracked files/directories for a commit, run:

```
git add <file/directory> <file/directory> ...
```

To commit any staged modified tracked or untracked files/directories to your
local repository run:

```
git commit <-a> -m "<some comment>"
```

Rather than individually staging any modified tracked files, you can stage them
all at once using the `<-a>` option with the above command. Note that this will
not stage any untracked files. Which commands to use to stage files/directories
depends on the situation. Individually staging files with `git add` gives you
more control over which changes will be part of the next commit whereas using
the `<-a>` option reduces the amount of typing necessary to stage all modified
tracked files.

Finally, push the committed file/directories in your local repository to the
remote repository with:

```
git push origin master
```

You should now be able to see the modified files/directories in the remote
repository through the web browser.


## Grades

To avoid issues with having to pull code from the remote repository, a new
branch called 'grade' will be created for you once the first assignment has been
graded. You can view your grades through the web browser by navigating to 
<https://github-dev.cs.illinois.edu/ECE220SU18/NetID.git> and clicing on the
button that says `Branch: master`. Click on the `grade` option and this will
display a list of directories corresponding to each of your assignments. Inside
these directories, you will find a `grade.txt` file with your score.

[1]: https://wiki.illinois.edu/wiki/display/ece220su2/ECE+220+SU18+Home+Page
[2]: https://try.github.io/levels/1/challenges/1
[3]: https://jan-krueger.net/wordpress/wp-content/uploads/2007/09/git-cheat-sheet.pdf
[4]: https://www.patrickzahnd.ch/blog.html#gitflow
[5]: https://git-scm.com/book/en/v2
