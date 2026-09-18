using System;

class Program
{
    static void Main()
    {
        //Inicio de la programacion para la funcion "suma"
        Console.Write("Ingrese el valor del primer número: ");
        int a = Convert.ToInt32(Console.ReadLine());
        Console.Write("Ingrese el valor del segundo número: ");
        int b = Convert.ToInt32(Console.ReadLine());
        int resultado = suma(a, b);
        Console.WriteLine("La suma es: " + resultado);
        //Fin de la programacion para la funcion "suma"

        // Inicio de la programacion de la funcion "registroAsistencia" (El primer valor es de "Asistencia", el segundo valor es de "Tarde")
        registroAsistencia(true, false);
        registroAsistencia(false, true);
        registroAsistencia(true, true);
        // Fin de la programacion de la funcion "registroAsistencia"

        // Inicio de la programacion de la función "sumatoria"
        int inicio, fin;
        do
        {
            Console.WriteLine("Ingrese el valor de 'Inicio': ");
            inicio = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Ingrese el valor de 'Fin': ");
            fin = Convert.ToInt32(Console.ReadLine());
            if (fin > inicio)
            {
                Console.WriteLine("Error: 'Fin' debe ser menor o igual a 'Inicio', intente nuevamente.");
            }

        } while (fin > inicio);
        double resultadoSumatoria = Sumatoria(inicio, fin);
        Console.WriteLine("El resultado de la sumatoria es: " + resultadoSumatoria);
        // Fin de la programacion de la función "sumatoria"

        // Inicio de la programacion de la función "comparador"
        Console.Write("Ingrese el valor para x: ");
        char x = char.Parse(Console.ReadLine());
        Console.Write("Ingrese el valor para y: ");
        char y = char.Parse(Console.ReadLine());
        Console.Write("Ingrese el valor para z: ");
        char z = char.Parse(Console.ReadLine());
        char baseChar = Comparador(x, y, z);
        Console.WriteLine($"El valor es: {baseChar}");
        // Fin de la programacion de la función "comparador"

        // Inicio de la programacion de la función "sencillo"
        double monto;
        do
        {
            Console.WriteLine("Ingrese el monto:");
            monto = Convert.ToDouble(Console.ReadLine());
            if (monto < 0)
            {
                Console.WriteLine("Error: El valor del monto debe ser positivo. Inténtelo nuevamente.");
            }
        } while (monto < 0);
        Sencillo(monto);
        // Fin de la programacion de la función "sencillo"
    }

    //---------------------------------------------------------------------------------------------------------------------//

    // Inicio de la función "suma"
    static int suma(int a, int b)
    {
        return a + b;
    }
    // Fin de la función "suma"

    // Inicio de la función "registroAsistencia"
    static void registroAsistencia(bool Asistencia, bool Tarde)
    {
        if (Asistencia && !Tarde)
        {
            Console.WriteLine("Asistencia valida");
        }
        else if (!Asistencia)
        {
            Console.WriteLine("No asistencia");
        }
        else if (Asistencia && Tarde)
        {
            Console.WriteLine("Asistencia tarde");
        }
    }
    // Fin de la función "registroAsistencia"

    // Inicio de la función "sumatoria"
    static double Sumatoria(int Inicio, int Fin)
    {
        int suma = 0;
        for (int i = Inicio; i <= Fin; i++)
        {
            suma += i;
        }
        if (suma % 2 == 0)
        {
            return 3.141516;
        }
        else if (suma % 2 != 0)
        {
            return 2.68;
        }
        else
        {
            return suma * -1;
        }
    }
    // Fin de la función "sumatoria"

    // Inicio de la función "comparador"
    static char Comparador(char x, char y, char z)
    {
        if (x == y && y == z)
        {
            Console.WriteLine("Todos los valores son iguales");
            return x;
        }

        if ((x >= y && x <= z) || (x <= y && x >= z))
        {
            return x;
        }
        else if ((y >= x && y <= z) || (y <= x && y >= z))
        {
            return y;
        }
        else
        {
            return z;
        }
    }
    // Fin de la función "comparador"

    // Inicio de la función "sencillo"
    static void Sencillo(double Dinero)
    {
        int billetes100 = (int)(Dinero / 100);
        Dinero %= 100;
        int billetes50 = (int)(Dinero / 50);
        Dinero %= 50;
        int billetes20 = (int)(Dinero / 20);
        Dinero %= 20;
        int billetes10 = (int)(Dinero / 10);
        Dinero %= 10;
        int billetes5 = (int)(Dinero / 5);
        Dinero %= 5;
        int monedas1 = (int)(Dinero);
        Dinero %= 1;
        int centavosEnteros = (int)(Dinero * 100);
        Console.WriteLine($"Billetes de 100 = {billetes100}");
        Console.WriteLine($"Billetes de 50 = {billetes50}");
        Console.WriteLine($"Billetes de 20 = {billetes20}");
        Console.WriteLine($"Billetes de 10 = {billetes10}");
        Console.WriteLine($"Billetes de 5 = {billetes5}");
        Console.WriteLine($"Monedas de 1 = {monedas1}");
        Console.WriteLine($"Centavos = {centavosEnteros}");
    }
    // Fin de la función "sencillo"
}

