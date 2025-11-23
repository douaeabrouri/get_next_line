#!/bin/bash

if [ -p /dev/stdin ]; then
  text="$(cat)"
elif [ $# -gt 0 ]; then
  if command -v "$1" >/dev/null 2>&1; then
    text="$("$@")"
  else
    text="$*"
  fi
else
  echo "Usage:"
  echo "  ./rainbow.sh "some text""
  echo "  ./rainbow.sh ls"
  echo "  ./your_program | ./rainbow.sh"
  exit 1
fi

for ((i=0; i<${#text}; i++)); do
  color=$((31 + i % 6))
  printf "\033[%sm%s\033[0m" "$color" "${text:$i:1}"
  sleep 0.02
done
printf "\n"