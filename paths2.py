from collections import defaultdict

def solution(members, events):
    mention_count = defaultdict(int)
    active_users = set(members)
    offline_times = {}

    for event in events:
        timestamp = int(event[1])
        if event[0] == "OFFLINE":
            user_id = event[2]
            offline_times[user_id] = timestamp + 60
            active_users.discard(user_id)
        elif timestamp <= max(offline_times.get(user_id, 0) for user_id in members):
            mentions = event[2].split()
            for mention in mentions:
                if mention == "ALL":
                    mention_count["ALL"] += len(active_users)
                elif mention == "HERE":
                    mention_count["HERE"] += len(active_users)
                elif mention in members:
                    mention_count[mention] += 1

    result = []
    for member in sorted(members):
        result.append(f"{member}={mention_count.get(member, 0)}")

    return result

# Example usage:
members = ["id42", "id158", "id23"]
events = [
    ["MESSAGE", "0", "ALL id158 id42"],
    ["OFFLINE", "1", "id158"],
    ["MESSAGE", "2", "id158 id158"],
    ["OFFLINE", "3", "id23"],
    ["MESSAGE", "60", "HERE id158 id42 id23"],
    ["MESSAGE", "61", "HERE"]
]
print(solution(members, events))
