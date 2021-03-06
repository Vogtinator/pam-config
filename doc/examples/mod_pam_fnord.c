/* Copyright (C) 2007 Sven Schober
   Author: Sven Schober <sschober@suse.de>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 2 as
   published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "pam-config.h"
#include "pam-module.h"

static int
parse_config_fnord (pam_module_t *this, char *args, write_type_t type)
{
  option_set_t *opt_set = this->get_opt_set( this, type );

  if (debug)
    printf("**** parse_config_fnord (%s): '%s'\n", type2string(type),
           args?args:"");

  opt_set->enable (opt_set, "is_enabled", TRUE);

  return TRUE;
}

static int
write_config_fnord (  pam_module_t *this,
		      enum write_type op __attribute__((unused)),
		      FILE *unused __attribute__((unused)))
{
  option_set_t *opt_set = this->get_opt_set (this, SESSION);
  if (debug)
    printf ("**** write_config_fnord (...)\n");
  return TRUE;
}



DECLARE_BOOL_OPTS_1( is_enabled );
DECLARE_STRING_OPTS_0;
DECLARE_OPT_SETS;

pam_module_t mod_pam_fnord = { 
  "pam_fnord.so",	  /**< module name */ 
  opt_sets,		  /**< list option_set_t's defined by DECLARE_OPT_SETS */
  &parse_config_fnord,	  /**< parse function pointer */
  &def_print_module,	  /**< print function pointer */
  &write_config_fnord,	  /**< write function pointer */
  &get_opt_set		  /**< accessor for option sets */
};
