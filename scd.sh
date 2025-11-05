#! /bin/bash

starting_dir=$(pwd)

if [ $# -eq 0 ]; then
	cd ~
	return
fi

if [[ $1 = "-" ]]; then
	cd -
	return
fi

for dir in $@
do
	current_dir=$(pwd)
	if [ -d "$dir" ]; then
		cd $dir
	else
		cd "$(find . -type d -name $dir -print -quit)"
		new_dir=$(pwd)
		if [ $new_dir = $current_dir ]; then
			cd $starting_dir
			echo "scd: '${dir}' not found."
			return
		fi
	fi
done

OLDPWD=$starting_dir
