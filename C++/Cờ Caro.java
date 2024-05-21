package BTL;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Iterator;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Game extends JFrame implements MouseListener{
	private JPanel mainP, p1, p2;
	private JButton[][] arBT;
	private boolean[][] arrEnd;
	private int[][] arr;
	private JButton btnReset;
	private boolean turn;
	private boolean endGame=false;
	
	public Game() {
		arBT=new JButton[3][3];
		arr=new int[3][3];
		arrEnd=new boolean[3][3];
		
		taoGUI();
		
		setTitle("Game XO");
		setSize(300,350);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	private void taoGUI() {
		add(mainP=new JPanel());
		addP1();
		mainP.add(p2=new JPanel(),BorderLayout.SOUTH);
		p2.setPreferredSize(new Dimension(300,100));
		p2.add(btnReset=new JButton("Reset"));
		btnReset.setEnabled(false);
		btnReset.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				reset();
			}
		});
	}
	
	private void reset() {
		for (int i = 0; i < arBT.length; i++) {
			for (int j = 0; j < arBT.length; j++) {
				arBT[i][j].setText("");
				arrEnd[i][j]=false;
				arr[i][j]=0;
			}
		}
		endGame=false;
		turn=false;
		btnReset.setEnabled(false);
	}
	
	private void addP1() {
		mainP.add(p1=new JPanel(),BorderLayout.CENTER);
		p1.setLayout(new GridLayout(3,3));
		for(int i=0;i<arBT.length;i++) {
			for(int j=0;j<arBT[i].length;j++) {
				arBT[i][j]=new JButton();
				arBT[i][j].addMouseListener(this);
				arBT[i][j].setPreferredSize(new Dimension(80,80));
				arBT[i][j].setBackground(Color.black);
				arBT[i][j].setForeground(Color.white);
				arBT[i][j].setFont(new Font("Arial",Font.BOLD,40));
				p1.add(arBT[i][j]);
			}
		}
	}
	
	private int checkResult(int[][] arr) {
		for(int i=0;i<arr.length;i++) {
			int a=arr[i][0];
			if(a==arr[i][1] && a==arr[i][2]) {
				if(a==1) {
					return -10;
				}else if(a==2) {
					return 10;
				}
			}
		}
		for(int i=0;i<arr.length;i++) {
			int a=arr[0][i];
			if(a==arr[1][i] && a==arr[2][i]) {
				if(a==1) {
					return -10;
				}else if(a==2) {
					return 10;
				}
			}
		}
		if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2]) {
			if(arr[0][0]==1) {
				return -10;
			}else if(arr[0][0]==2) {
				return 10;
			}
		}
		if(arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2]) {
			if(arr[2][0]==1) {
				return -10;
			}else if(arr[2][0]==2) {
				return 10;
			}
		}
		return 0;
	}
	
	private boolean checkMove(int[][] arr) {
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[i].length;j++) {
				if(arr[i][j]==0) {
					return true;
				}
			}
		}
		return false;
	}
	
	private int minimax(int arr[][],boolean isTurn) {
		int s=checkResult(arr);
		if(s==10)	return s;
		if(s==-10) return s;
		if(checkMove(arr)==false)	return 0;
		if(isTurn==true) {
			int best=-10000;
			for(int i=0;i<arr.length;i++) {
				for(int j=0;j<arr[i].length;j++) {
					if(arr[i][j]==0) {
						arr[i][j]=2;
						best=Math.max(minimax(arr, !isTurn), best);
						arr[i][j]=0;		
					}
				}
			}
			return best;
		}else {
			int best=10000;
			for(int i=0;i<arr.length;i++) {
				for(int j=0;j<arr[i].length;j++) {
					if(arr[i][j]==0) {
						arr[i][j]=1;
						best=Math.min(minimax(arr, !isTurn), best);
						arr[i][j]=0;		
					}
				}
			}
			return best;
		}	
	}
	
	public Point bestMove(int[][] arr,boolean turn) {
		int best=-1000;
		Point result=new Point();
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[i].length;j++) {
				if(arr[i][j]==0) {
					arr[i][j]=2;
					int score=minimax(arr, !turn);
					arr[i][j]=0;
					if(score>best) {
						best=score;
						result.x=i;
						result.y=j;
					}
				}
			}
		}
		return result;
	}
	
	public void end() {
		for (int i = 0; i < arBT.length; i++) {
			for (int j = 0; j < arBT.length; j++) {
				arrEnd[i][j]=true;
			}
		}
	}

	public static void main(String[] args) {
		new Game();
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(MouseEvent e) {
		for(int i=0;i<arBT.length;i++) {
			for(int j=0;j<arBT[i].length;j++) {
				if(e.getButton()==1 && e.getSource()==arBT[i][j] && turn==false && arrEnd[i][j]==false) {
					arBT[i][j].setText("x");
					arr[i][j]=1;
					arrEnd[i][j]=true;
					turn=true;
					btnReset.setEnabled(true);
				}
			}
		}
		if(turn==true) {
			Point p=bestMove(arr, turn);
			int i=(int)p.getX();
			int j=(int)p.getY();
			arBT[i][j].setText("o");
			arrEnd[i][j]=true;
			arr[i][j]=2;
			turn =false;
		}
		int check=checkResult(arr);
		if(check==10 &&!endGame) {
			end();
			JOptionPane.showConfirmDialog(null, "Computer win","End",JOptionPane.DEFAULT_OPTION);
			endGame=true;
		}else if(check==-10&&!endGame) {
			end();
			JOptionPane.showConfirmDialog(null, "Human win","End",JOptionPane.DEFAULT_OPTION);
			endGame=true;
		}
		if(!endGame) {
			if(!checkMove(arr)) {
				JOptionPane.showConfirmDialog(null, "Tie","End",JOptionPane.DEFAULT_OPTION);
				endGame=true;
			}
		}
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
}
