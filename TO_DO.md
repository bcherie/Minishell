Переменные окружения в экзек ве

command result
redirect -> out 

funct(5, 3)
	return (5 * 3)


		"version": "0.2.0",
	"configurations": [
		{
			"name": "(lldb) Launch",
			"type": "cppdbg",
			"request": "launch",
			"program": "${workspaceFolder}/minishell",
			"args": [],
			"stopAtEntry": true,
			"cwd": "${workspaceFolder}",
			"environment": [],
			"externalConsole": true,
			"MIMode": "lldb"
		}
	]
}