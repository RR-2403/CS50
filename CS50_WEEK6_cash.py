from cs50 import get_float

while True:
    change=get_float("CHANGE: ")
    if change>0:
        break

total_cents=int(change*100)

quarter=int(total_cents/25)
total_cents-=quarter*25

dimes=int(total_cents/10)
total_cents-=dimes*10

nickel=int(total_cents/5)
total_cents-=nickel*5

pennies=total_cents

total_coins=quarter+dimes+nickel+pennies

print(total_coins)
