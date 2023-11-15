#include "shell.h"

/**
 * find_command_in_path - Searches for a command in the PATH
 * @cmd: Command to search for
 * Return: Full path to the command or NULL if not found
 */
char *find_command_in_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy, *dir;
	char *full_path = malloc(MAX_CMD_LEN);

	if (!full_path)
		return (NULL);
	if (!path)
	{
		free(full_path);
		return (NULL);
	}
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_path, MAX_CMD_LEN, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	free(full_path);
	return (NULL);
}
