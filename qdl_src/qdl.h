#ifndef __QDL_H__
#define __QDL_H__

#include <stdbool.h>

#include "patch.h"
#include "program.h"
#include <libxml/tree.h>

struct qdl_device;

int qdl_read(struct qdl_device *qdl, void *buf, size_t len, unsigned int timeout);
int qdl_write(struct qdl_device *qdl, const void *buf, size_t len, unsigned int timeout);

int firehose_run(struct qdl_device *qdl, const char *incdir, const char *storage, unsigned int read_timeout, unsigned int write_timeout);
int sahara_run(struct qdl_device *qdl, char *prog_mbn, unsigned int timeout);
void print_hex_dump(const char *prefix, const void *buf, size_t len);
unsigned attr_as_unsigned(xmlNode *node, const char *attr, int *errors);
const char *attr_as_string(xmlNode *node, const char *attr, int *errors);

extern bool qdl_debug;

#endif
