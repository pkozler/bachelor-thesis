using static System.Console;

namespace JavaClasses
{

    public class ScannerTest
    {

        public int errorsInMethod { get; private set; } = 0;

        private delegate bool EqualsMethod<T>(T expected, T actual);

        private delegate T ScanMethod<T>();

        private void assertEquals<T>(string name, T expected, ScanMethod<T> scan, EqualsMethod<T> equals)
        {
            WriteLine();
            WriteLine("Testovaná metoda: \"{0}\"", name);
            T actual;
            WriteLine("Očekávaná hodnota: \"{0}\"", expected);

            try
            {
                actual = scan();
            }
            catch (System.Exception e)
            {
                WriteLine("CHYBA: " + e.Message);
                errorsInMethod++;
                return;
            }

            if (equals(expected, actual))
            {
                WriteLine("OK");
            }
            else
            {
                WriteLine("FAIL - skutečná hodnota: \"{0}\"", actual);
                errorsInMethod++;
            }
        }

        private void nextAssertEquals(Scanner sc, String expected)
        {
            assertEquals("next", expected, sc.next, (e, a) =>
            {
                return e.equals(a);
            });
        }

        private void nextBooleanAssertEquals(Scanner sc, bool expected)
        {
            assertEquals("nextBoolean", expected, sc.nextBoolean, (e, a) =>
            {
                Boolean x = new Boolean(e);
                Boolean y = new Boolean(a);

                return x.equals(y);
            });
        }

        private void nextByteAssertEquals(Scanner sc, sbyte expected)
        {
            assertEquals("nextByte", expected, sc.nextByte, (e, a) =>
            {
                Byte x = new Byte(e);
                Byte y = new Byte(a);

                return x.equals(y);
            });
        }

        private void nextShortAssertEquals(Scanner sc, short expected)
        {
            assertEquals("nextShort", expected, sc.nextShort, (e, a) =>
            {
                Short x = new Short(e);
                Short y = new Short(a);

                return x.equals(y);
            });
        }

        private void nextIntAssertEquals(Scanner sc, int expected)
        {
            assertEquals("nextInt", expected, sc.nextInt, (e, a) =>
            {
                Integer x = new Integer(e);
                Integer y = new Integer(a);

                return x.equals(y);
            });
        }

        private void nextLongAssertEquals(Scanner sc, long expected)
        {
            assertEquals("nextLong", expected, sc.nextLong, (e, a) =>
            {
                Long x = new Long(e);
                Long y = new Long(a);

                return x.equals(y);
            });
        }

        private void nextFloatAssertEquals(Scanner sc, float expected)
        {
            assertEquals("nextFloat", expected, sc.nextFloat, (e, a) =>
            {
                Float x = new Float(e);
                Float y = new Float(a);

                return x.equals(y);
            });
        }

        private void nextDoubleAssertEquals(Scanner sc, double expected)
        {
            assertEquals("nextDouble", expected, sc.nextDouble, (e, a) =>
            {
                Double x = new Double(e);
                Double y = new Double(a);

                return x.equals(y);
            });
        }

        private void nextLineAssertEquals(Scanner sc, String expected)
        {
            assertEquals("nextLine", expected, sc.nextLine, (e, a) =>
            {
                return e.equals(a);
            });
        }

        /// <summary>
        /// Tests the constructor.
        /// </summary>
        public void scannerTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);
            
            // random test of different type values scanning
            nextAssertEquals(a, "a");
            nextBooleanAssertEquals(a, false);
            nextByteAssertEquals(a, 0);
            nextShortAssertEquals(a, 0);
            nextIntAssertEquals(a, 0);
            nextLongAssertEquals(a, 0);
            nextFloatAssertEquals(a, 0.1f);
            nextDoubleAssertEquals(a, 0.1);
            nextLineAssertEquals(a, " ");
        }

        /// <summary>
        /// Tests the next method.
        /// </summary>
        public void nextTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            // scanning of strings delimited by different counts of whitespaces
            nextAssertEquals(a, "test1");
            nextAssertEquals(a, "test2");
            nextAssertEquals(a, "test3");
            nextAssertEquals(a, "test4");
            nextAssertEquals(a, "test5");
            nextAssertEquals(a, "true");
            nextAssertEquals(a, "1");
            nextAssertEquals(a, "1.0");
            nextAssertEquals(a, ".");
        }

        /// <summary>
        /// Tests the nextBoolean method.
        /// </summary>
        public void nextBooleanTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            // scanning of strings representing bool values
            nextBooleanAssertEquals(a, true);
            nextBooleanAssertEquals(a, true);
            nextBooleanAssertEquals(a, false);
            nextBooleanAssertEquals(a, true);
            nextBooleanAssertEquals(a, false);
            nextBooleanAssertEquals(a, false);
            nextBooleanAssertEquals(a, true);
            nextBooleanAssertEquals(a, false);
        }

        /// <summary>
        /// Tests the nextByte method.
        /// </summary>
        public void nextByteTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            // scanning of integers (zeroes, ones, positive and negative minimal and maximal values)
            nextByteAssertEquals(a, (sbyte)0);
            nextByteAssertEquals(a, (sbyte)0);
            nextByteAssertEquals(a, (sbyte)0);
            nextByteAssertEquals(a, (sbyte)1);
            nextByteAssertEquals(a, (sbyte)1);
            nextByteAssertEquals(a, (sbyte)-1);
            nextByteAssertEquals(a, (sbyte)127);
            nextByteAssertEquals(a, (sbyte)127);
            nextByteAssertEquals(a, (sbyte)-127);
            nextByteAssertEquals(a, (sbyte)-128);
        }

        /// <summary>
        /// Tests the nextShort method.
        /// </summary>
        public void nextShortTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            nextShortAssertEquals(a, (short)0);
            nextShortAssertEquals(a, (short)0);
            nextShortAssertEquals(a, (short)0);
            nextShortAssertEquals(a, (short)1);
            nextShortAssertEquals(a, (short)1);
            nextShortAssertEquals(a, (short)-1);
            nextShortAssertEquals(a, (short)32767);
            nextShortAssertEquals(a, (short)32767);
            nextShortAssertEquals(a, (short)-32767);
            nextShortAssertEquals(a, (short)-32768);
        }

        /// <summary>
        /// Tests the nextInt method.
        /// </summary>
        public void nextIntTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            nextIntAssertEquals(a, (int)0);
            nextIntAssertEquals(a, (int)0);
            nextIntAssertEquals(a, (int)0);
            nextIntAssertEquals(a, (int)1);
            nextIntAssertEquals(a, (int)1);
            nextIntAssertEquals(a, (int)-1);
            nextIntAssertEquals(a, (int)2147483647);
            nextIntAssertEquals(a, (int)2147483647);
            nextIntAssertEquals(a, (int)-2147483647);
            nextIntAssertEquals(a, (int)-2147483648);
        }

        /// <summary>
        /// Tests the nextLong method.
        /// </summary>
        public void nextLongTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            nextLongAssertEquals(a, (long)0L);
            nextLongAssertEquals(a, (long)0L);
            nextLongAssertEquals(a, (long)0L);
            nextLongAssertEquals(a, (long)1L);
            nextLongAssertEquals(a, (long)1L);
            nextLongAssertEquals(a, (long)-1L);
            nextLongAssertEquals(a, (long)9223372036854775807L);
            nextLongAssertEquals(a, (long)9223372036854775807L);
            nextLongAssertEquals(a, (long)-9223372036854775807L);
            nextLongAssertEquals(a, (long)-9223372036854775808L);
        }

        /// <summary>
        /// Tests the nextFloat method.
        /// </summary>
        public void nextFloatTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            /* 
             scanning of decimal values
             (with and without sign and decimal dot and with omission of digits on different positions,
             scanning of zeroes, ones, minimal and maximal absolute values)
            */
            nextFloatAssertEquals(a, (float)0.0F);
            nextFloatAssertEquals(a, (float)0.0F);
            nextFloatAssertEquals(a, (float)-0.0F);
            nextFloatAssertEquals(a, (float)0.0F);
            nextFloatAssertEquals(a, (float)0.0F);
            nextFloatAssertEquals(a, (float)-0.0F);
            nextFloatAssertEquals(a, (float)0.0F);
            nextFloatAssertEquals(a, (float)0.0F);
            nextFloatAssertEquals(a, (float)-0.0F);
            nextFloatAssertEquals(a, (float)0.0F);
            nextFloatAssertEquals(a, (float)0.0F);
            nextFloatAssertEquals(a, (float)-0.0F);
            nextFloatAssertEquals(a, (float)1.0F);
            nextFloatAssertEquals(a, (float)1.0F);
            nextFloatAssertEquals(a, (float)-1.0F);
            nextFloatAssertEquals(a, (float)1.0F);
            nextFloatAssertEquals(a, (float)1.0F);
            nextFloatAssertEquals(a, (float)-1.0F);
            nextFloatAssertEquals(a, (float)0.1F);
            nextFloatAssertEquals(a, (float)0.1F);
            nextFloatAssertEquals(a, (float)-0.1F);
            nextFloatAssertEquals(a, (float)0.1F);
            nextFloatAssertEquals(a, (float)0.1F);
            nextFloatAssertEquals(a, (float)-0.1F);
            nextFloatAssertEquals(a, (float)3.4028235E38F);
            nextFloatAssertEquals(a, (float)3.4028235E38F);
            nextFloatAssertEquals(a, (float)-3.4028235E38F);
            nextFloatAssertEquals(a, (float)1.4E-45F);
            nextFloatAssertEquals(a, (float)1.4E-45F);
            nextFloatAssertEquals(a, (float)-1.4E-45F);
        }

        /// <summary>
        /// Tests the nextDouble method.
        /// </summary>
        public void nextDoubleTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            nextDoubleAssertEquals(a, (double)0.0);
            nextDoubleAssertEquals(a, (double)0.0);
            nextDoubleAssertEquals(a, (double)-0.0);
            nextDoubleAssertEquals(a, (double)0.0);
            nextDoubleAssertEquals(a, (double)0.0);
            nextDoubleAssertEquals(a, (double)-0.0);
            nextDoubleAssertEquals(a, (double)0.0);
            nextDoubleAssertEquals(a, (double)0.0);
            nextDoubleAssertEquals(a, (double)-0.0);
            nextDoubleAssertEquals(a, (double)0.0);
            nextDoubleAssertEquals(a, (double)0.0);
            nextDoubleAssertEquals(a, (double)-0.0);
            nextDoubleAssertEquals(a, (double)1.0);
            nextDoubleAssertEquals(a, (double)1.0);
            nextDoubleAssertEquals(a, (double)-1.0);
            nextDoubleAssertEquals(a, (double)1.0);
            nextDoubleAssertEquals(a, (double)1.0);
            nextDoubleAssertEquals(a, (double)-1.0);
            nextDoubleAssertEquals(a, (double)0.1);
            nextDoubleAssertEquals(a, (double)0.1);
            nextDoubleAssertEquals(a, (double)-0.1);
            nextDoubleAssertEquals(a, (double)0.1);
            nextDoubleAssertEquals(a, (double)0.1);
            nextDoubleAssertEquals(a, (double)-0.1);
            nextDoubleAssertEquals(a, (double)1.7976931348623157E308);
            nextDoubleAssertEquals(a, (double)1.7976931348623157E308);
            nextDoubleAssertEquals(a, (double)-1.7976931348623157E308);
            nextDoubleAssertEquals(a, (double)4.9E-324);
            nextDoubleAssertEquals(a, (double)4.9E-324);
            nextDoubleAssertEquals(a, (double)-4.9E-324);
        }

        /// <summary>
        /// Tests the nextLine method.
        /// </summary>
        public void nextLineTest()
        {
            Scanner a;
            a = new Scanner(System_.in_);

            // scanning of lines with different types of string
            nextLineAssertEquals(a, "");
            nextLineAssertEquals(a, " ");
            nextLineAssertEquals(a, "   ");
            nextLineAssertEquals(a, "test");
            nextLineAssertEquals(a, "this is another test");
            nextLineAssertEquals(a, " this is another test ");
            nextLineAssertEquals(a, "   this is another test   ");
            nextLineAssertEquals(a, "   this is   another test   ");
        }
        
    }

}

