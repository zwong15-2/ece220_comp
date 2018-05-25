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

To be able to retrieve assignments from the `_release` repository you have to
add it as a remote:

```
git remote add release
https://github-dev.cs.illinois.edu/ECE220SU18/_release.git
```

You can check whether the remote was added:

```
git remote -v
```

### Retrieve assignments

To retrieve (or updated) released assignments, run:

```
git fetch release
git merge release/<assignment> -m "<some comment>"
``` 

where `<assignment>` is a branch name corresponding to a particular assignment
and `<some comment>` is a comment of your choice.

### Submit assignments

To submit (or update) completed assignments, you will to follow these steps.

To see all modified and untracked files in your Git workspace, run:

```
git status
```

To add untracked files and modified files/directories, run:

```
git add <file/directory> <file/directory> ...
```

To commit newly added files/directories to your local repository and those with
changes run:

```
git commit <-a> -m "<some comment>"
```

To automatically stage modified/deleted files that have already been added in
the past, you can simply include the `<-a>` option. This way, you won't have to
run `git add ...` on files that are being already tracked. Excluding this option
gives you more control over the files you wish to commit.

Finally, push the changes in your local repository to the remote repository
with:

```
git push origin <assignment>
```

### Switching branches

To view other assignments, you will need to switch branches. You can see which
branch you are currently on with:

```
git branch
```

To change to another branch, run:

```
git checkout <assignment>
```

Please commit all your work before switching branches to minimize data loss.

## Grades


[1]: https://wiki.illinois.edu/wiki/display/ece220su2/ECE+220+SU18+Home+Page
[2]: https://try.github.io/levels/1/challenges/1
[3]: https://jan-krueger.net/wordpress/wp-content/uploads/2007/09/git-cheat-sheet.pdf
[4]: https://www.patrickzahnd.ch/blog.html#gitflow
[5]: https://git-scm.com/book/en/v2
