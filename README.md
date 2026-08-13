# REMINDME

remindme is a quick and easy (but very useful) reminder tool written in C;
for when you suddenly have to jump up from your work, half-written line of code in progress,
and want to remember what you were doing when you come back in a week from saving the world.

creating a reminder:

```
remindme currently working on unit tests for the email sending API, specifically the HELO headers.
```

This creates a .remindme file in the current directory.

To *be* reminded, just make sure you're in that directory and type

```
remindme
```

To delete a .remindme file, type:

```
remindme -d
```

For all of the above, you can specify a path parameter if you want to store a reminder somewhere other than the current directory.

```
remindme -p subfolder/subsubfolder currently working on blah blah blah

remindme -p subfolder/subsubfolder

remindme -p subfolder/subsubfolder -d
```

All flags (-d and the path flag) must go before your message, or they will be counted as part of it.

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
For any programmers, the help.txt file is included using <code>xxd -c 256 -i help.txt</code>
</sub>