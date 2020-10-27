/* vk_platformer.c
 *
 * Copyright 2020 Arydev
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <stdlib.h>

#ifndef MAIN_c
#define MAIN_C
#endif

int main (int argc,char *argv[]){
    printf ("By arydev\n");

    create_instance();
    // Update

    //exit
    vkClear();


    return EXIT_SUCCESS;
}
