#include <displayservice.h>
#ifdef PROJECT_NAME
static char projectName[] = PROJECT_NAME;
#else 
static char projectName[] = "UNDEFINED";
#endif

#ifdef PROJECT_VER
static char projectVer[] = PROJECT_VER;
#else 
static char projectVer[] = "UNDEFINED";
#endif

#ifdef PROJECT_AUTHOR
static char projectAuthor[] = PROJECT_AUTHOR;
#else 
static char projectAuthor[] = "UNDEFINED";
#endif

#ifdef PROJECT_GITHUBDIR
static char projectGithubdir[] = PROJECT_GITHUBDIR;
#else 
static char projectGithubdir[] = "UNDEFINED";
#endif


int get_project_name();
void draw_project_info( sFONT *Font, bool includeVersion, bool includeAuthor, bool includeGitHub);