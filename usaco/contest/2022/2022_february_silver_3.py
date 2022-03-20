import sys

# (greedy algorithm)
# 1 sort as many email as possible
# 2 scroll folder as long as top folder is satisfied
# 3 scroll email by once and add as many emails as possible
# 4 repeat, if emails are still left then no, else yes

# this is really shoddy oh my god
def simulate_emails(emails, folder_num, window_h):
    folders = {}
    for folder in emails:
        if folder in folders:
            folders[folder] += 1
        else:
            folders[folder] = 1
    
    email_top = 0
    email_bottom = min(len(emails)-1, window_h-1)
    folder_bottom = min(folder_num, window_h)
    filed = 1

    while filed > 0:
        filed = 0
        for i in range(email_top, email_bottom+1):
            if emails[i] >= 0 and emails[i] <= folder_bottom:
                folders[emails[i]] -= 1
                emails[i] = -1
                filed += 1
        
        email_bottom += filed
        email_top += filed
        if email_bottom > len(emails)-1:
            email_top -= email_bottom-len(emails)+1
            email_bottom = len(emails)-1

        scroll_folder = False

        while folders[folder_bottom-(min(folder_num-1, window_h-1))] == 0:
            scroll_folder = True
            folder_bottom += 1
            if folder_bottom >= folder_num:
                return True
        
        old_email_top = email_top
        if not scroll_folder and filed == 0:
            filed = 1
            email_bottom += 1
            email_top += 1
            if email_bottom > len(emails)-1:
                email_top -= email_bottom-len(emails)+1
                email_bottom = len(emails)-1
            
            if email_top == old_email_top:
                return False

    return False

n = int(sys.stdin.readline())

for i in range(n):
    header = [int(x) for x in sys.stdin.readline().split()]
    folder_count, email_count, height = header[0], header[1], header[2]
    emails = [int(x) for x in sys.stdin.readline().split()]
    if simulate_emails(emails, folder_count, height):
        print("YES")
    else:
        print("NO")