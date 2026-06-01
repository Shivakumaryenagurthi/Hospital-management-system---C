CC     = gcc
CFLAGS = -Wall -Wextra -g

TARGET = hospital

SRCS = main.c \
       check_duplicate.c \
       book_appointment.c \
       print_all.c \
       print_by_acc.c \
       print_by_doctor.c \
       print_by_disease.c \
       print_menu.c \
       save.c \
       find.c \
       modify.c \
       delete.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c patient.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
