// Tic-tac-toe
// Игра "Крестики-нолики"
// CPU играет против пользователя

/*
Создать пустое поле для игры в крестики-нолики
Вывести на экран правила игры
Определить, кто ходит первым
Отобразить поле
Если пока никто не победил и наступила ничья
	И если сейчас ход пользователя
		Получить ход пользователя
		Обновить игровое поле с учетом хода пользователя
	Иначе
		Вычислить ход CPU
		Обновить поле с учетом хода CPU
	Отобразить поле
	Передать ход сопернику
Поздравить победителя или объявить ничью
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// глобальные константы
const char X      = 'X';
const char O      = 'O';
const char EMPTY  = ' ';
const char TIE    = 'T';
const char NO_ONE = 'N';

// прототипы функций
void instructions();
char ask_yes_no(string question);
int ask_number(string question, int high, int low=0);
char human_piece();
char opponent(char piece);
void display_board(const vector<char> &board);
char winner(const vector<char> &board);
bool is_legal(const vector<char> &board, int move);
int human_move(const vector<char> &board, char human);
int cpu_move(vector<char> board, char cpu);
void announce_winner(char winner, char cpu, char human);

// ==============================
int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);

	instructions();

	char human = human_piece();
	char cpu = opponent(human);
	char turn = X;

	display_board(board);

	while(winner(board) == NO_ONE)
	{
		if(turn == human)
		{
			move = human_move(board, human);
			board[move] = human;
		}
		else
		{
			move = cpu_move(board, cpu);
			board[move] = cpu;
		}
		display_board(board);
		turn = opponent(turn);
	}

	announce_winner(winner(board), cpu, human);

	return 0;
}

// ==============================
void instructions()
{
	cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
	cout << "--where human brain is pit against silicon processor\n\n";
	cout << "Make your move known by entering a number, 0 - 8. The number\n";
	cout << "corresponds to the desired board position, as illustrated:\n\n";
	cout << " 0 | 1 | 2\n";
	cout << " ---------\n";
	cout << " 3 | 4 | 5\n";
	cout << " ---------\n";
	cout << " 6 | 7 | 8\n\n";
	cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}
// ==============================
char ask_yes_no(string question)
{
	char response;
	do
	{
		cout << question << " (y/n): ";
		cin >> response;
	} while(response != 'y' && response != 'n');

	return response;
}

// ==============================
int ask_number(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while(number > high || number < low);

	return number;
}

// ==============================
char human_piece()
{
	char go_first = ask_yes_no("Do you require the first move?");

	if(go_first == 'y')
	{
		cout << "\nThen take the first move. You will need it.\n";
		return X;
	}
	else
	{
		cout << "\nYour bravery will be your undoing... I will go first.\n";
		return O;
	}
}

// ==============================
char opponent(char piece)
{
	if(piece == X)
		return O;
	else
		return X;
}

// ==============================
void display_board(const vector<char> &board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}

// ==============================
char winner(const vector<char> &board)
{
	// все возможные выигрышные ряды
	const int WINNING_ROWS[8][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6},
	};

	const int TOTAL_ROWS = 8;
	// если в одном из выигрышных рядов уже присутствуют три одинаковых значения
	// (причем они не равны EMPTY), то победитель определился
	for(int row = 0; row < TOTAL_ROWS; ++row)
	{
		if( (board[WINNING_ROWS[row][0]] != EMPTY) &&
		(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
		(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
			return board[WINNING_ROWS[row][0]];
	}

	// поскольку победитель не определился, проверяем, не наступила ли ничья
	// (остались ли на поле пустые клетки)
	if(count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;

	// поскольку победитель не определился, но и ничья еще не наступила,
	// игра продолжается
	return NO_ONE;
}

// ==============================
inline bool is_legal(int move, const vector<char> &board)
{
	return (board[move] == EMPTY);
}

// ==============================
int human_move(const vector<char> &board, char human)
{
	int move = ask_number("Where will you move?", board.size() - 1);

	while(!is_legal(move, board))
	{
		cout << "\nThat square is already occupied, foolish human.\n";
		move = ask_number("Where will you move?", board.size() - 1);
	}

	cout << "Fine...\n";
	return move;
}

// ==============================
int cpu_move(vector<char> board, char cpu)
{
	unsigned int move = 0;
	bool found = false;

	// если cpu может выиграть следующим ходом, то он делает этот ход
	while(!found && move < board.size())
	{
		if(is_legal(move, board))
		{
			board[move] = cpu;
			found = winner(board) == cpu;
			board[move] = EMPTY;
		}
		if(!found)
			++move;
	}

	// иначе если человек может победить следующим ходом, блокировать этот ход
	if(!found)
	{
		move = 0;
		char human = opponent(cpu);
		while(!found && move < board.size())
		{
			if(is_legal(move, board))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if(!found)
				++move;
		}
	}

	// иначе занять следующим ходом оптимальную свободную клетку
	if(!found)
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

		// выбрать оптимальную свободную клетку
		while(!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if(is_legal(move, board))
				found = true;

			++i;
		}
	}

	cout << "I shall take square number " << move << endl;

	return move;
}
// ==============================
void announce_winner(char winner, char cpu, char human)
{
	if(winner == cpu)
	{
		cout << winner << "'s won!\n";
		cout << "As I predicted, human. I am triumphat once more -- proof\n";
		cout << "that computers are superior to humans in all regards.\n";
	}
	else if(winner == human)
	{
		cout << winner << "'s won!\n";
		cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
		cout << "But never again! I, the computer, so swear it!\n";
	}
	else
	{
		cout << "It's a tie.\n";
		cout << "You were most lucky, human, and somehow managed to tie me.\n";
		cout << "Celebrate... for this is the best you will ever achieve.\n";
	}
}
