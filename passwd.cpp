#include <cstdio>
#include <cstring>

char name[65], old_passwd[65], new_passwd[65];

const char ch[90] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 
    '!', '@', '#', '$', '%', '^', '&', '*',
    '(', ')', '_', '+', '-', '=', '{', '}',
    '[', ']', '?', '/', ':', ';',
    '\\', '.', ',', '>', '<'
};

int main() {
    printf("User:");
    scanf("%s", name);
    
    printf("Password:");
    scanf("%s", old_passwd);
    
    unsigned long long name_sum = 0, pass_sum = 0;
    int name_len = strlen(name), old_passwd_len = strlen(old_passwd);
    
    for (int i = 63; i >= 0; i--) {
        name[i] = name[i % name_len];
        old_passwd[i] = old_passwd[i % old_passwd_len];
        
        name_sum *= 131ULL;
        name_sum += 1ULL * name[i];
        pass_sum *= 137ULL;
        pass_sum += 1ULL * old_passwd[i];
        
        if (i < 3) new_passwd[i] = ch[1ULL * (name_sum * 139ULL + pass_sum * 149ULL) % 52];
        else if (i >= 3 && i < 6) new_passwd[i] = ch[1ULL * (name_sum * 139ULL + pass_sum * 149ULL) % 10 + 52];
        else if (i >= 6 && i < 8) new_passwd[i] = ch[1ULL * (name_sum * 139ULL + pass_sum * 149ULL) % 27 + 62];
        else new_passwd[i] = ch[1ULL * (name_sum * 139ULL + pass_sum * 149ULL) % 89];
    }
    printf("Your new password:\n");
    printf("8  digits: %.8s\n", new_passwd);
    printf("16 digits: %.16s\n", new_passwd);
    printf("32 digits: %.32s\n", new_passwd);
    printf("64 digits: %.64s\n", new_passwd);
    return 0;
}
