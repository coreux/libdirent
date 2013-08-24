/*
 * Copyright 2013 Mo McRoberts.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
http://pubs.opengroup.org/onlinepubs/009695399/basedefs/dirent.h.html
*/

#ifndef __UX_DIRENT_H
# define __UX_DIRENT_H                 1

# include <ux/cdefs.h>
# include <ux/features.h>
# include <ux/kerntypes.h>

/* ino_t */
# include <ux/inodef.h>

struct dirent
{
	ino_t d_ino;                          /* File serial number */
	char d_name[];                        /* Name of entry */
};

typedef struct __ux_dir_struct DIR;

__UX_BEGIN_DECLS

int closedir(DIR *dir) __UX_SYM03(closedir);
DIR *opendir(const char *path) __UX_SYM03(opendir);
struct dirent *readdir(DIR *dir) __UX_SYM03(readdir);
# if __UX_OPT_TSF >= 0
int readdir_r(DIR *restrict dir, struct dirent *restrict entry, struct dirent **restrict result) __UX_SYM03(readdir_r);
# endif
void rewinddir(DIR *dir) __UX_SYM03(rewinddir);
void seekdir(DIR *dir, long location) __UX_SYM03(seekdir);
long telldir(DIR *dir) __UX_SYM03(telldir);

__UX_END_DECLS

#endif /*!__UX_DIRENT_H*/
