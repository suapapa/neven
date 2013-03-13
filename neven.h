#ifndef _NEVEN_H
#define _NEVEN_H

struct neven_env {
	void *fd;
	void *sdk;
	void *dcr;
	int width;
	int height;
};

struct neven_face {
	float confidence;
	float midpointx;
	float midpointy;
	float eyedist;
};

struct neven_env *neven_create(int w, int h, int maxFaces);
void neven_destroy(struct neven_env *env);
int neven_detect(struct neven_env *env, void *bwbuffer);
void neven_get_face(struct neven_env *env, struct neven_face *face, int index);

#endif
