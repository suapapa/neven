#ifndef _NEVEN_H
#define _NEVEN_H

#define NEVEN_INIT_DATA_ROOT	"/usr/local/share/neven/bmd/"
#define NEVEN_INIT_DATA_PREC	NEVEN_INIT_DATA_ROOT "RFFprec_501.bmd"
#define NEVEN_INIT_DATA_SPEED	NEVEN_INIT_DATA_ROOT "RFFspeed_501.bmd"
#define NEVEN_INIT_DATA_STD	NEVEN_INIT_DATA_ROOT "RFFstd_501.bmd"

struct neven_env {
	void *fd;
	void *sdk;
	void *dcr;
	int width;
	int height;
};

struct neven_point {
	float x;
	float y;
};

struct neven_face {
	struct neven_point lefteye;
	struct neven_point righteye;
	struct neven_point midpoint;
	float eyedist;
	float confidence;
};

struct neven_env *neven_create(int w, int h, int max_faces,
			       const char *init_data_path);
void neven_destroy(struct neven_env *env);
int neven_detect(struct neven_env *env, void *bwbuffer);
void neven_get_face(struct neven_env *env, struct neven_face *face, int index);

#endif
