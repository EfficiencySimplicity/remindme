#!/bin/zsh
# https://superuser.com/questions/601480/always-run-a-command-after-another-command/1462004#1462004
# https://stephenweiss.dev/zsh-hooks

# Hook onto `chpwd` in the right way
# with the official util add-zsh-hook

# wrap remindme into a function
function remindme_on_cwd_change() {
  remindme
}

autoload -Uz add-zsh-hook
add-zsh-hook chpwd remindme_on_cwd_change
