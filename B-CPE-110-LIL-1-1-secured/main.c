#include "include/my.h"

int main(void)
{
    int len = 5;
    hashtable_t *ht = new_hashtable(&hash, len);

    ht_insert(ht, "dqdsqdqdqs", "mail_compte4");
    ht_insert(ht, "qsdqsdsqdqs", "mail_compte3");
    ht_insert(ht, "gfhgjfdsq", "mail_compte1");
    ht_insert(ht, "azertyuio", "mail_compte2");
    ht_dump(ht);
    delete_hashtable(ht);
}
