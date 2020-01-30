using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Replacr
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ReplaceBtn_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string stringToReplaceValue = stringToReplace.Text;
                string replaceValueValue = replaceValue.Text;
                string originalStringValue = originalString.Text;
                string output = originalStringValue.Replace(stringToReplaceValue, replaceValueValue);
                result.Text = output;
            }
            catch
            {
                MessageBox.Show("An error occured. Please enter all required values.");
            }
        }
    }
}
