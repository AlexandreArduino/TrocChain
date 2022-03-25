#pragma once

#define LEN_SHA256 65

struct IdentityObject {
    char id[LEN_SHA256];
    char password_hash[LEN_SHA256];
    char next_id[LEN_SHA256];

}__attribute__((packed));

extern struct IdentityObject null_user;