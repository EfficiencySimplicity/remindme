# REMINDME

remindme is a quick and easy (but very useful) reminder tool written in C;
for when you suddenly have to jump up from your work, half-written line of code in progress,
and want to remember what you were doing when you come back in a week from saving the world.

creating a reminder:

```
remindme that Im currently working on unit tests for the email sending API, specifically the HELO headers.
```

This creates a .remindme file in the current directory.

To *be* reminded, just make sure you're in that directory and type

```
remindme
```

To delete a .remindme file, type:

```
remindme delete
```

to add .remindme to your .gitignore, type:

```
remindme ignore
```

to hook remindme into zsh so that it calls on every directory change, type:

```
remindme pester
```

You can also access help:

```
remindme help
```
(or -h, or --h, or -help, or --help)

<sub>
Besides leaving quick notes when you have to leave fast, you could also use remindme to store the current state of a project that you may not come back to for years and years or so, although there may be an inverse correlation between length of time away and shortest possible message that can serve as an adequate mental refresher
</sub>

<br>

<sub>
For any programmers, the help.txt file (and all text files included in remindme.c) are included using <code>xxd -c 256 -i</code>
</sub>