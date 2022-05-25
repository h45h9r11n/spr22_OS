#include <security/pam_modules.h>
#include <stdarg.h>
#include <time.h>

#define PAM_SM_AUTH
#define MAX_V 30


PAM_EXTERN int pam_sm_authenticate(pam_handle_t * pamh, int flags
                                   ,int argc, const char **argv)
{
        unsigned int ctrl;
        int retval;
        const char *name, *p;
        char *right;
        long x1,x2,y;

       
        x1=random()%MAX_V;
        x2=random()%MAX_V;
       
       
        retval = pam_get_user(pamh, &name, "login: ");


        {
            struct pam_conv *conv;
            struct pam_message *pmsg[3],msg[3];
            struct pam_response *response;


        retval = pam_get_item( pamh, PAM_CONV, (const void **) &conv ) ;

        pmsg[0] = &msg[0];
        msg[0].msg_style = PAM_PROMPT_ECHO_OFF;
        msg[0].msg=malloc(100);
        snprintf(msg[0].msg,60,"Second Password: %d + %d = ?",x1,x2);

        retval = conv->conv(1, ( const struct pam_message ** ) pmsg
                            , &response, conv->appdata_ptr);
 
        y=x1+x2;
        right=malloc(100);
        snprintf(right,20,"%d",y);
 
        if (!(strcmp(right,response->resp))){
        return PAM_SUCCESS;
        }else{
        return PAM_AUTH_ERR;
        }
      }
        return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_setcred(pam_handle_t * pamh, int flags
                              ,int argc, const char **argv)
{
        unsigned int ctrl;
        int retval;


        retval = PAM_SUCCESS;

        return retval;
}

#ifdef PAM_STATIC
struct pam_module _pam_unix_auth_modstruct = {
    "[pam_test",
    pam_sm_authenticate,
    pam_sm_setcred,
    NULL,
    NULL,
    NULL,
    NULL,
};
#endif
