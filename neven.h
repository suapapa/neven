#ifndef _NEVEN_H
#define _NEVEN_H

#define NEVEN_INITDATA_ROOT	"/usr/local/share/neven/bmd/"
#define NEVEN_INITDATA_PREC	NEVEN_INITDATA_ROOT "RFFprec_501.bmd"
#define NEVEN_INITDATA_SPEED	NEVEN_INITDATA_ROOT "RFFspeed_501.bmd"
#define NEVEN_INITDATA_STD	NEVEN_INITDATA_ROOT "RFFstd_501.bmd"

typedef struct {
	void *fd;
	void *sdk;
	void *dcr;
	int width;
	int height;
} neven_env_t;

typedef struct {
	float x;
	float y;
} neven_point_t;

typedef struct {
	neven_point_t lefteye;
	neven_point_t righteye;
	neven_point_t midpoint;
	float eyedist;
	float confidence;
} neven_face_t;

neven_env_t *neven_create(int w, int h, int max_faces,
			  const char *initdata_path);
void neven_destroy(neven_env_t *env);
int neven_detect(neven_env_t *env, void *bwbuffer);
void neven_get_face(neven_env_t *env, neven_face_t *face, int index);
#endif
