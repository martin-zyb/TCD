#include <iostream>
using namespace std;

typedef int Color;

class CXY
{
private:
	int s_num;
	Color s_color;
public:
	void AddData(int num, Color color);
	Color GetColorData();
	int GetPlaceData();
};

void CXY::AddData(int num, Color color)
{
	s_num = num;
	s_color = color;
}

Color CXY::GetColorData()
{
	return s_color;
}

int CXY::GetPlaceData()
{
	return s_num;
}

class DarwMaps
{
private:
	CXY* s_cxy[2];
public:

	void Bind(CXY* cx, CXY* cy);
	void Unbind();
	void Add(int opt, int num, int pos, Color color);
	Color Get(int x, int y);
};

void DarwMaps::Bind(CXY* cx, CXY* cy)
{
	s_cxy[0] = cx;
	s_cxy[1] = cy;
}

void DarwMaps::Unbind()
{
	s_cxy[0] = nullptr;
	s_cxy[1] = nullptr;
}

void DarwMaps::Add(int opt, int num, int pos, Color color)
{
	s_cxy[opt][pos].AddData(num, color);
}

Color DarwMaps::Get(int x, int y)
{
	if (s_cxy[0][x].GetPlaceData() > s_cxy[1][y].GetPlaceData())
	{
		return s_cxy[0][x].GetColorData();
	}
	else if (s_cxy[0][x].GetPlaceData() < s_cxy[1][y].GetPlaceData())
	{
		return s_cxy[1][y].GetColorData();
	}
	else
	{
		return Color(0);
	}
}

int main()
{
	int t, n, m, q;
	short opt;
	int pos;
	Color color;

	std::cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		std::cin >> n >> m >> q;
		CXY* cx = new CXY[n+10];
		CXY* cy = new CXY[m+10];
		for (int j = 1; j <= n; ++j) cx[j].AddData(0, 0);
		for (int j = 1; j <= m; ++j) cy[j].AddData(0, 0);
		DarwMaps* darwmaps = new DarwMaps;
		darwmaps->Bind(cx, cy);
		for (int j = 1; j <= q; ++j)
		{
			cin >> opt >> pos >> color;
			darwmaps->Add(opt, j, pos, color);
		}
		for (int j = 1; j <= n; ++j)
		{
			for (int l = 1; l <= m; ++l)
			{
				color = darwmaps->Get(j, l);
				std::cout << color << " ";
			}
			std::cout << "\n";
		}
		darwmaps->Unbind();
		delete darwmaps;
		delete[] cx;
		delete[] cy;
	}
	return 0;
}