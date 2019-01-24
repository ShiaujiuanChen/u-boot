#include <environment.h>
#include "via.h"

#if defined(CONFIG_CMD_SAVEENV) && !defined(CONFIG_ENV_IS_NOWHERE)
static int bDestroyEnv = 0;

int in_destroyenv(void)
{
	return bDestroyEnv;
}

static int do_destroyenv(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int nResult;

	bDestroyEnv = 1;
	nResult = env_save() ? 1 : 0;
	bDestroyEnv = 0;

	return nResult;
}

U_BOOT_CMD(
	destroyenv, CONFIG_SYS_MAXARGS, 0, do_destroyenv,
	"destroy enviroment variables stored in medium",
	"\n	- destroy all environment variables in medium"
	"\n	  after reset the default settings will be used"
);
#endif
