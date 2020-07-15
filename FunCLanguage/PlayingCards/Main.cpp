#include <iostream>
#include <iomanip>
#include <regex>
#include <string>
#include <windows.h>
#include <lmcons.h>
#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <psapi.h>
#include <wtsapi32.h>
#include <vector>
#include <algorithm>

#include "Deck.h"

using namespace std;

template <typename Array, int N>
constexpr int arraySize(Array(&)[N]) { return N; }

#pragma region MainLoop
/// <summary>ゲームマネージャクラス</summary>
class GameManager
{
private:

	static const int SEC = 1000;			/// <summary>ミリ秒</summary>
	static const int BaseScore = 10 * 60;	/// <summary>基準スコア</summary>

	/// <summary>デバッグモード</summary>
	bool debugMode = false;
	/// <summary>ゲームステータス</summary>
	int state = MENU;
	/// <summary>スコア</summary>
	int score = 0;
	/// <summary>デッキ</summary>
	Deck deck = Deck();
	/// <summary>今のカード</summary>
	Card nowCard = Card();
	/// <summary>引いたカード</summary>
	Card drawCard = Card();

	/// <summary>違反プレイヤ判定</summary>
	bool badPlayer = false;
	/// <summary>自動勝利機能</summary>
	bool AutoWin = false;

	/// <summary>よく気付いたな、勝利コマンドだ！</summary>
	const string IOftenFound = "qpmz";

	/// <summary>メニューテキスト</summary>
	const string MenuInfo =
		"━━━━━━━━━━━　High & Low　━━━━━━━━━━━━━━━━　\n"
		"ルール\n"
		"コンソール上に表示された数よりデッキから引いた数が\n"
		"高いか低いかを当てるゲームです。\n"
		"数が同じの場合は高いと判定されます。\n"
		"高いと思った場合：High（ h ）\n"
		"低いと思った場合：Low （ l ）\n"
		"を入力してください。\n"
		"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━　\n"
		"\n\n\n"
		"ゲームを始めますか？\n"
		"Yes（ y ）：はじめる\n"
		"No （ n ）：おわる\n";

	/// <summary>ゲームクリアテキスト</summary>
	const string GOOD_JOB =
		"･+ﾟ'(ﾉ｡´∀｀)ﾉ ヽ(´ε｀｡ヽ)'ﾟ+｡\n"
		"Game Clear!!\n"
		"ﾟ*｡☆ヾ(´∀｀)(´∀｀)ノ☆。*ﾟ\n\n";

#pragma region VIOLATION
	const string MenuBadInfo =
		"━━━━━━━━━━━　High & Low　━━━━━━━━━━━━━━━━　\n"
		"ルール\n"
		"ルールを守り楽しく遊びましょう。\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"以上\n"
		"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━　\n"
		"\n\n\n"
		"ゲームを始めますか？\n"
		"Yes（ y ）：はじめる\n"
		"No （ n ）：おわる\n";

	const string CanNotTurnBack =
		"━━━━━━━━━━━　High & Low　━━━━━━━━━━━━━━━━　\n"
		"ルール\n"
		"コンソール上に表示された数よりデッキから引いた数が\n"
		"高いか低いかを当てるゲームです。\n"
		"数が同じの場合は高いと判定されます。\n"
		"高いと思った場合：High（ h ）\n"
		"低いと思った場合：Low （ l ）\n"
		"を入力してください。\n"
		"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━　\n"
		"\n\n\n"
		"ゲームを始めますか？\n"
		"Yes（ y ）：つづく\n"
		"No （ n ）：つづく\n";

	const string AA_HORROR =
		"纛纛纛纛纛竇纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛驪曩竇纛竇纛竇竃襲亜茜意ひかあ哀ざ仝ぜ娃ぼ闇廳纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛竇纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛竇竇驪纛纛爨竇爨鱸窺握営むがさ哀往亜位あ杏祟握園鰯爨纛驪纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛竇纛纛纛纛纛纛竇纛曩爨驪驪囑曩茜絢引かにね位ぜあ哀仝ね往さ姶轄爨爨竇轟纛纛竇纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛驪纛纛纛纛纛纛纛纛纛纛纛鱸纛纛纛纛纛纛纛竇轟旭爨嚢悪鵬ぽぜづごひせ引禾さざぃひざぬぽ芦愛鱸爨纛爨纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛纛竇竇纛纛纛纛竇纛竇曩驪宛轟韻あ祟づぐアシりりえむね引ね依むぜぱ依依葦欝囑纛襲纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛竇竇纛竇纛竇驪纛竇鱸曩位轟鰻ぃ〆アぐ？ノシノノべしご？？づしせ往哀ぬ亜廳鰯纛鱸纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛鱸竃竇驪竇竇醜襲醜曩鏖加くぃ？そかりノノぃぃぃぃぃ？し禾そ唖娃ぜ営囈鰻竇馨纛纛纛纛纛纛纛纛纛纛纛纛維纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛竇鰯曩竇纛竇竇竃鱸鰻襲襲愛アノ？し巾呪ねくノノノノノノノノシね巾え安劃馨轄纛疊纛纛纛纛纏纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛疊曩竇驪竇纛竇轟愛欝襲が禾ぇぃぃ〆韻姶あ引ノノノノノノノににぃぃくぼ丑囈呪纛纏驪纛纛纛竇纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛疊纛竇纛纛爨爨轟窺竃竃囈醜ねノ握哀姶渥馨姶杏ぃノノノノノノノノノノノノそ闇娃纛曩鵬纛纛纛竇纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛竇纛纛竇纛竇纛爨驪襲纛纛纛竇爨轟嚢謂磯呪鰻鱸馨ぱ握鰻餓劃窺ばりノノノノノノノノノノノノく引ノ鰯驪廳纛纛纛竇纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛鱸纛纛竇纛竇驪襲爨竇竇纛竇纛鏖轟纛纛纛纛纛娃握竇艶疊醜悪逢娃そノノノノノノノノノノノノノ々ノ纏園ア竇竇纛竇驪纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛竇纛纛竇竇纛轟纛竇纛纛纛竇竇爨纛纛纛爨纛纛纛娃馨竇鱸鏖醐意さむぃノノノノノノノノノノぃノ？ノ鞍竃ぃ醐纛驪纛纛纛纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛竇纛竇纛纛驪竇轟纛纛纛纛囑轟纛纛纛ぼ馨爨纏醜営あ杏えノノノノノノノノノノぃノアノ鱸愛々逢驪竇纛曩驪纛竇纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛驪纛竇纛纛纛纛醜纛纛纛纛廳纛纛纛纛杏呪纛轟醜餓ぼあさノノノノノノノノノノノぃづノ欝葵醜劃鱸爨纛阿竇纛竇纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛竇竇纛爨纛纛纛轟纛竇纛纛纛纛纛纛纛纛纛維仝曩驪竃嚇哀ね仝ノノノノノノノノノノノ？哀宛醜磯襲疊纏纛竇ア廳纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛轟轟纛纛竇驪襲鰯纛纛竇曩竃纛纛纛纛劃杏攬纛疊園芦ぱぜ？ノノノノノノノノノぃむ攬轟驪鱸爨鱸園驪鏖馨鏖驪纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛嚢竇纛纛纛鱸鰻茜鏖ぐ纛竇疊纛纛纛纛纛ぼ位園纛鏖攬祟むざりノノノノノノノノノ握驪竃曩爨纛鱸襲醐爨鱸爨曩纛纛纛竇纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛纛纛纛驪鏖鏖驪竇纛纏むぐ園廳鏖驪竇疊纛纛纛竇ぬ園鏖竇爨馨娃かむかぃノノノノノノぇ囈廳ぃぐ驪纛爨驪〆ア醜鱸嚇竃纛纛纛纛竇竇纛纛纛纛纛\n"
		"纛纛纛纛竇竇纛竇襲襲爨竇驪驪驪べノノぐ逢竃曩纛纛纛竇鞍阿園轟鱸驪醐阿むせ禾ざノノノノノ〆意くぃ竇纛爨纛爨纛纛ぇ穐ぼ悪竇竇纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛竇纛驪驪鱸囑竇爨驪轟鰯愛ノノノノノア醐轟竇鱸鱸襲爨襲欝驪闇位引ねぽ葦づノノぃアノし曩轄闇轄鵬竇竇爨竇ア竃磯か竇驪纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛竇爨襲曩曩驪鏖驪疊嚢鱸ぐノノノノノノ？劃竃竇纛竇嚢竇鏖唖ざか芦ぼ握闇？ノノぃ襲疊往位竃爨纛纛纛纛襲襲竃爨園竇鏖纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛竇爨謂驪鰻鏖襲轟穐園廳鰯攬禾ノノノノノし廳鵬襲疊鏖轟鰯鰻旭けそぱ旭劃馨ごべぃ驪嚢園依纛纛竇纛竇纛纛纛襲驪廳欝竇纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛餓竇竇鱸鱸鱸鱸茜餓攬醐纏維穐曩アノノノノ〆纏驪曩轟鱸攬鞍ねづそ丑阿艶醜謂ぼ爨爨廳穐謂纛纛纛纛驪纛纛纛驪曩馨鱸鏖竇纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛纛驪囑丑鱸鏖驪窺葦磯窺宛安ば馨が粟挨絢か醜驪竇驪竃囈謂芦ひりけ杏旭園鰯鵬竇竇曩轟闇纛纛纛纛愛纛纛纛纛纛鵬鏖欝竃纛纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛竇驪杏仝曩握爨あか呪穐絢シ〆ノぃ？ぃぼ呪鱸鱸鰯欝攬逢旭巾づ々え杏営韻疊爨纛さ驪鰯葦纛纛纛纛纛纛纛纛纛纛り鰯呪艶曩纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛轟驪呪鵬纏依りづぃにひぬごくノノノノにぼ廳劃艶愛挨杏け引アぐごさ姶攬竃園驪纛纛驪鰯纛纛纛纛纛纛纛纛纛纛醐襲轄驪驪纛纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛竇ああく引葦娃くノそぃえノぃぃそ？りり意逢呪依往ぜさ禾ひけえせせ絢欝爨磯ぽ轟鱸竇轟纛纛纛纛纛纛纛纛纛纛鱸纛廳纛爨爨纛纛纛轟纛纛纛纛纛\n"
		"纛纛纛纛竇む？ぬ驪〆ぃノ？ぜノひシ？ぃぐかけ巾加祟維粟ぬぜ禾娃位かひせあ茜磯爨驪加づ纏あ轟纛纛纛纛纛纛纛纛纛爨竇纛曩轟竇曩纛纛纛纛纛纛纛纛纛\n"
		"纛纛纛纛驪驪けくべ葦ノ？く〆し？シノぃノノぃ？ぽ闇穐愛逢粟唖ぽぽ丑さ仝あ亜磯疊爨轟巾ぃ囈絢ぇ嚢驪纛轟纛纛纛纛竇竇驪鱸竇竇竇竇竇纛纛纛纛纛纛纛\n"
		"纛纛纛纛嚢禾渥巾ぃぇべねぼシ引ノノノノノノノくぼざね禾依絢呪ばあかがせぽ安鞍闇疊驪園しノ々ノノぃ？囑曩竇纛竇竇竇纛爨纛竇驪曩襲纛纛纛纛纛纛纛\n"
		"纛纛纛纛竇ぇ仝挨ひべ巾ぃシご挨位むべノノノノに禾穐亜ぽ芦宛往ざか仝ば往芦阿芦維茜纏爨茜ノノノしノ？ノぐ々亜竃轟驪驪鰯纛竇竇驪爨纛纛纛纛纛纛纛\n"
		"纛纛纛纛窺安え握がごぃ竃竃ぃ絢穐鵬窺哀亜阿ぽぃ意葦ぼ依宛ぬざに引に依葵粟祟意姶茜磯疊驪鞍ざぃノぃぐひ韻鱸鏖爨驪竇轟ざ驪驪曩曩竇竇纛纛纛纛纛纛\n"
		"纛纛纛纛ばひに々シ巾？曩襲曩べ鏖鏖囑馨鰻園渥ぃノぇぼ杏娃粟巾丑ぬ芦阿葵粟安葵ご丑営磯鰯嚢営窺窺ね〆劃轟爨曩爨疊囑窺愛鱸葵竇囈爨驪纛驪纛纛纛纛\n"
		"纛纛纛纛驪ぇ葵々くぬ旭鱸疊嚇絢鵬鏖疊鱸囈醐嚇悪ノノぃノぃば宛ば往芦葦営旭ぱ宛ねノ仝呪馨纏囑〆馨往醜ご葦鞍鱸爨往にに爨鱸纛ぐ襲曩鰯纛驪纛纛纛纛\n"
		"纛纛纛纛逢ご禾？シ加園疊轟杏醜？引轟竃曩鏖園悪宛ぃづノノノノ？々ざそア祟呪葦むノぃぱ禾廳艶嚢磯位祟々位巾え鰻シノし纛爨纛驪べ襲鰯竇纛纛纛纛纛\n"
		"纛纛纛纛曩〆葦ぃづ握曩鏖纛祟鱸渥ぃぐ愛轟纛鰯廳茜祟？ぃノノノノノノノノそ園廳ノノノぃ〆禾闇安娃葵かぇぐ々ぃ々ノノ竃纛爨鰯鱸爨醜竇竇纛纛纛纛纛\n"
		"纛纛纛纛曩爨醐ひぽ加竃竃纛纛粟握宛ノぃに轄爨鰯艶握呪ぃノノノノノノノぃノぃ々ノノノノ々しぼ謂絢巾ざべ？ノノか？ノ纛嚢竇鵬纛轟竇嚇竇纛竇纛纛纛\n"
		"纛纛纛纛纛爨粟さ渥渥爨韻纛纛驪姶安ぃノぃねかぽ磯纏劃茜ぃぃノノノノノぃノノノノノノノノシ〆安宛えぐ？ぃノノむぃべ纛竇纛轟竇竇轟せ竇纛纛纛纛纛\n"
		"纛纛纛纛纛驪穐芦轄呪愛ぼ纛竇曩仝え劃ノノぃせさ丑絢鱸磯姶営ノノノノノぃぇぃノノノノノノノ々〆禾りシノノノノぐぃ竃纛爨竃驪葵曩囈驪攬爨纛纛纛纛\n"
		"纛纛纛纛驪纛疊づ鞍攬鏖巾竇爨驪シ位鞍鞍さぃノぃ往〆娃欝竃窺鞍あアシに芦ぜざしくノノノノノノぃくしノぃノノノノ位驪纛曩竇轟纛醐闇驪攬爨纛纛纛纛\n"
		"纛纛纛纛纛轟驪渥宛穐纏加轟纛欝嚇哀宛唖亜窺ノノノシにかむ竇鰯醜馨韻餓韻磯窺渥唖ば丑ぇぃぃ？ぃノノノノノノノ〆葵纛竇爨纛鱸曩爨驪竇竇竇纛纛纛纛\n"
		"纛纛纛纛爨纛竇爨む馨韻鵬鵬竇鱸鰯鰯むご仝依ひかそノノぇべくぇべぃぃ？？し阿囑鏖疊嚢轄轄娃丑ごノノノノノノ々ノ鰯爨纛驪纛曩囑爨爨園竇襲竇纛纛纛\n"
		"纛纛纛纛纛竇竇轟窺に韻囈醐纛馨馨醐ぃ？粟唖亜粟悪ノノノ々ノノく？しづぃノしノノ？ぇか？？ぇぃえ？ノノべ々がべ醜囈纛攬纛竇鱸曩竇纛曩丑曩纛纛纛\n"
		"纛纛纛纛纛竇纛竇園ぬ加闇嚇竇悪絢鰻ぃ？位〆え宛謂粟べノくぃノノノノノノノノぃノノぃぃぃえ爨鰯醜ざノぃごづぃ纛意竇纛爨纛纛轟曩驪纛纛纛襲纛纛纛\n"
		"纛纛纛纛纛竇竇竇茜ノぐ韻鰻襲醐唖餓轄驪？ノく茜葵旭位丑悪？ノノノノノノノノノノぃノ愛宛驪纛廳嚢づ？くノノ仝竇？竇驪鱸竇爨竇驪竇纛纛醜轟纛纛纛\n"
		"纛纛纛纛纛纛竇竇鏖〆艶位葵囈襲握窺謂驪しノし安ひシご芦？シ往宛唖営仝々娃営し々むざ茜驪纛曩馨囈づノノノし驪纛欝竇纛襲竇纛驪鱸纛纛纛驪仝竇纛纛\n"
		"纛纛纛纛纛纛纛纛纛えごむ握営囈意旭謂鵬艶園？ごぐべぇさ維に〆が姶しざそノぇ〆往々む纏襲竇廳韻にノノノア轟纛竇鵬纛竇竃ひ愛り襲纛纛纛纛づ驪纛纛\n"
		"纛纛纛纛纛纛纛竇竇安べ哀茜悪囈窺阿窺園絢鰻醜？ノノシぬけごシ々娃ぬくし亜〆ア逢ぃ嚢纏驪欝韻馨ぃしし〆ぬ竇纛囑爨爨纛悪纛纛曩竇纛纛纛纛娃竇纛纛\n"
		"纛纛纛纛纛纛纛纛鱸渥ノ旭轄嚢磯ぼ握窺餓劃欝維芦ぐぃノ粟ノ々り？安ぃ？？？安丑囈囈醜鱸醜握襲そえぇがね竇纛纛纛纛襲纛ぽ驪爨纛纛纛纛纛纛嚇纛纛纛\n"
		"纛纛纛纛纛纛纛纛竇ぽべ？悪鰻維謂艶窺旭醐葵葵廳磯粟渥悪ぃぃノノ謂ぃぃ爨穐韻嚇醐鰯鱸疊握廳ぽ芦にぜ阿竇纛纛纛纛纛阿纛驪纛爨纛纛纛纛纛纛攬驪纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛禾加阿鰯園渥嚇園窺茜欝劃悪謂纏鰯艶粟餓呪営劃竃襲曩窺闇窺闇驪囈轄艶馨？〆ひ娃纛纛纛纛纛纛鱸あ纛纛驪襲纛纛纛纛纛纛嚇纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛竇加加意宛闇逢穐鰻挨ぜ窺襲囈劃攬加鰻艶鰻鰻絢維闇意窺握餓醐鰯闇鰯園ざ引ごが纛纛纛纛纛纛曩纛さ纛纛竇曩竇纛纛纛竇竇安爨纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛ノ茜安え旭餓逢姶磯茜位渥悪嚢醜欝醐囈鰻劃韻劃窺謂意轄嚢攬劃爨醜丑えぐひ纛纛纛纛纛纛纛纛纛驪纛竇逢爨纛纛纛纛鱸爨巾纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛窺せぇぜ引茜握愛艶嚇劃韻宛祟亜意握窺悪謂旭宛葦闇穐攬嚇馨纛意し巾づ祟醜纛纛纛纛纛纛纛纛纛竇窺驪驪曩驪纛纛纛鰯竇爨竇纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛渥絢ぃノね〆杏葦握韻劃園意鰻謂祟哀維悪維謂窺穐嚇磯磯欝竃窺しそぇ竇鰯纛纛纛纛纛纛纛纛纛艶纛葵韻姶竇驪鱸纛竇纏鰯竇竇纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛竇疊謂べシづ位ね位唖姶艶悪韻嚇渥磯囑窺餓劃鰻韻磯劃曩轟攬ぱ？？磯竇竇竇纛纛纛纛纛纛纛纛纛纛竇馨囈囑竇纛竇竇驪そ竇驪驪纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛竇竇ノノねさけ？引祟葦攬闇欝攬馨囈攬鵬馨醜鰯疊鰯馨挨々ぃ哀竇纛纛纛纛纛纛纛纛纛纛纛纛纛驪驪絢疊纛竇竇纛纛襲ぐ醜爨纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛竇纛纛疊ノノえ阿醐ぃご引が粟韻阿園穐鰻窺醐纏ぼぱ禾鱸ぃ引驪纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛竇囑宛鱸纛纛驪纛竇安ぜし驪竇纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛驪曩竇竇意？ノノ？べぃしべむ加あ丑廳唖呪営韻鰯醐娃阿曩纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛纛襲囈欝竇纛纛鰯竇疊に仝襲鏖驪纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛穐竇祟しぃノ引？ノノぃ？ぃノノノむ穐嚇亜？曩悪纛纛纛纛纛纛纛纛纛驪竇纛纛纛纛纛竇纛鰻嚇轟竇纛嚢驪驪攬ぜ穐轟挨竇纛纛\n"
		"纛纛纛纛纛轟纛纛纛纛纛纛纛竃纛爨加ぃぃノノノ？ぃノノノノノぃぃぃ宛竇纛驪竇纛纛纛纛纛纛轟轟爨竇纛纛纛纛纛竇竇醐廳纛竇纛轟囑加そ竇醜竇ぬ纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛竇纛疊纛粟悪しぃノノノノノノノノ？穐纛纛纛纛纛纛纛纛纛竇竇疊曩曩竇纛纛纛纛纛纛纛纛逢爨襲哀轟竇纛鞍韻曩爨纛？纛纛纛\n"
		"纛纛纛纛纛纛纛纛纛纛纛纛纛驪纛鱸纛纛鱸纏纏謂〆ぃ？ぃ？あ驪纛纛纛纛纛纛纛纛纛竇轟竃曩鏖爨纛纛纛纛纛纛纛纛纛纛竇纛窺纏纛竇爨餓べ竇あ竇意竇纛纛\n";

	static const int VIOLATION_LEN = 52;
	const char* ViolationMessage[VIOLATION_LEN] = {
		// 登場　4種
		"　　　　目\n\n",

		"　　　　目　口　　　　　　目\n\n",

		"　　　　目　目\n"
		"　　　　口\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口\n",

		// 挨拶　3種
		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　やあ\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%2d:%2d\n",			// 時間の取得 5

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s\n",					// 時間ごとのメッセージ表示 6

		// 言及　12種
		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　・・・・・・・・・・・・\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　きみは不正をしたっていうのにまだゲームをつづけるのかい？\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　一度、警告を出したはずなんだけど・・・\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　こりてないみたいだね\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　・・・・・・\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　・・・・・・・・・・・・・・・・・・\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　不正をするのはなにもくてきなんだい？\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　そんなにスコアがほしいのかい？\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s\n",							// 上の質問に対しての返事で分岐 15

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　そこまでしてしまうのなら手遅れか・・・\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　しかたないね\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s\n",							// 文字化け表示（10文字） 18

		// スコア破壊　5種類
		"　目　　目\n"
		"　　　口\n",

		"　　　　　　　　　　　目　　目\n"
		"　　　　　　　　　　　　口\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　よし\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口\n",

		// ユーザを見る・おどす　12種類
		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s\n",						// 文字化け表示（5文字） 24

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s\n",						// 文字化け表示（7文字） 25

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s\n",						// 文字化け表示（10文字） 26

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s\n",						// 文字化け表示（15文字） 27

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s\n",						// 文字化け表示（20文字） 28

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%sさんっていうんだね\n",	// ユーザ名表示 29

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　・・・・・・・・・\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　しらべれば何でもわかる\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　いつでも見ているぞ\n",

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s%s\n",		// 検索エンジン使用　メッセージ表示 33

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s%s\n",		// チャットソフト使用　メッセージ表示 34

		"　　　　目　　　　　目\n"
		"　　　　　　　口　　　　　　＜　%s%s\n",		// 録画ソフト使用　メッセージ表示 35

		// 身が崩れる　6種類
		"　　　　目　　　　　目\n"
		"　　　　　　　口\n",

		"　　　　目\n"
		"　　　　　　　口　　　目\n",

		"　　　　目\n"
		"　　　　　　　口　　　_\n",

		"\n"
		"　　　　_　　口　　　_\n",

		"\n"
		"　　　　_　　_　　　_\n",				// ここから赤文字 40

		"\n"
		"　　　_______________\n",

		// 意味深な話　5種類
		"僕は大学に進学することがきまり、マンションで1人暮らしすることになった。\n\n",
		"そのマンションに引っ越した時に、僕はリビングが見渡せる位置に小さな穴が開いていた。\n\n",
		"しかし、僕は新生活でドタバタしていたためあまり気にせず過ごしていた。\n\n",
		"ある日、友人からSNSで僕の部屋について詳細に説明されていると知らされた。\n\n",
		"僕はいそいで帰り、部屋の小さな穴を覗いてみたが真っ暗で隣の部屋をのぞくことはできなかった。\n\n",

		// もうすぐクリアだ　1種類
		"もうすぐクリアだね・・・・・・\n\n",

		// クリアなんてさせない　4種類
		"・・・・・・・・・\n\n",

		"クリアなんてさせない\n\n",

		"こんな方法で得たスコアなんて何の自慢にもならない\n\n",

		"\n\n"
	};

	int userReply = 0;
	int ViolationIndex = 0;
	vector<string> processList;

	static const int VIO_MESSAGE_5 = 5;
	static const int VIO_MESSAGE_6 = 6;
	static const int VIO_MESSAGE_14 = 14;
	static const int VIO_MESSAGE_15 = 15;
	static const int VIO_MESSAGE_18 = 18;
	static const int VIO_MESSAGE_24 = 24;
	static const int VIO_MESSAGE_25 = 25;
	static const int VIO_MESSAGE_26 = 26;
	static const int VIO_MESSAGE_27 = 27;
	static const int VIO_MESSAGE_28 = 28;
	static const int VIO_MESSAGE_29 = 29;
	static const int VIO_MESSAGE_33 = 33;
	static const int VIO_MESSAGE_34 = 34;
	static const int VIO_MESSAGE_35 = 35;
	static const int VIO_MESSAGE_40 = 40;

	static const int MORNING = 0;	// 朝
	static const int NOON = 1;		// 昼
	static const int EVENING = 2;	// 夕方
	static const int NIGHT = 3;		// 夜
	static const int MIDNIGHT = 4;	// 深夜

	const string TimeMessage[5] = {
		"朝からゲームかい？まあいいけど・・・\n",
		"お昼ご飯はもう食べたのかい？\n",
		"もう夕方かぁ、おなかすいてこない？\n",
		"夜なのにこれやってるって暇だね・・・\n",
		"深夜だっていうのに、なにをやっているんだい？\n"
	};

	static const int NS_YES = 0;
	static const int NS_NO = 1;
	static const int NS_NONE = 2;
	const string NeedScore[3] = {
		"だからってそこまでするか・・・",
		"うそだね",
		"なにも答えないんだね"
	};

	const string SearchEngine = "なんか開いて、なにをしらべていたんだい";
	const string ChatApp = "を開いているようだね、なにを話していたんだい";
	const string RecApp = "これは見せ物じゃないよ";


#pragma endregion

public:

	static const int MENU = 0;				/// <summary>ステータス：メニュー</summary>
	static const int PLAY = 1;				/// <summary>ステータス：プレイ</summary>
	static const int END = 2;				/// <summary>ステータス：エンド</summary>
	static const int EXIT = 3;				/// <summary>ステータス：終了</summary>
	static const int VIOLATION_START = 4;	/// <summary>違反ステータス：始まる</summary>
	static const int VIOLATION_GAME = 5;	/// <summary>違反ステータス：償い</summary>
	static const int VIOLATION_END = 6;		/// <summary>違反ステータス：解放</summary>
	static const int VIOLATION_MENU = 7;	/// <summary>違反ステータス：終焉</summary>

	static const int NONE = 0;	/// <summary>コマンド：なし</summary>
	static const int HIGH = 1;	/// <summary>コマンド：高い</summary>
	static const int LOW = 2;	/// <summary>コマンド：低い</summary>

	/// <summary>コンストラクタ</summary>
	GameManager();
	/// <summary>デストラクタ</summary>
	~GameManager();

	/// <summary>メインループ</summary>
	void MainLoop();
	/// <summary>メニュー表示</summary>
	void ShowMenu();
	/// <summary>ゲーム本編</summary>
	void PlayGame();
	/// <summary>ゲーム終了</summary>
	void GameEnd();

	/// <summary>標準入力</summary>
	string GetLine();
	/// <summary>コマンドチェック</summary>
	bool CheckCommand(string command, string check, string check2 = "");

#pragma region VIOLATION
	void ViolationStart();
	void ViolationGame();
	void ViolationEnd();
	void ViolationMenu();

	string Garble(int length);
	tm GetNowTime();
	void GetProcess();
	bool FindProcess(string name);

	void MsgRed() { printf("\x1b[31m"); }
	void MsgWhite() { printf("\x1b[37m"); }
#pragma endregion
};

/// <summary>コンストラクタ</summary>
GameManager::GameManager()
{
}

/// <summary>デストラクタ</summary>
GameManager::~GameManager()
{
}

/// <summary>メインループ</summary>
void GameManager::MainLoop()
{
	while (state != EXIT)
	{
		switch (state)
		{
		case MENU:ShowMenu(); break;
		case PLAY:PlayGame(); break;
		case END:GameEnd(); break;
#pragma region VIOLATION
		case VIOLATION_START:ViolationStart(); break;
		case VIOLATION_GAME:ViolationGame(); break;
		case VIOLATION_END:ViolationEnd(); break;
		case VIOLATION_MENU:ViolationMenu(); break;
#pragma endregion
		default:state = EXIT; break;
		}
	}
}

/// <summary>メニュー表示</summary>
void GameManager::ShowMenu()
{
	std::system("cls");

	// 初期化
	deck.Init();
	deck.Shuffle();
	score = 0;
	AutoWin = false;
	nowCard = deck.GetCard();
	deck.Next();

	// メニューの表示
	if (!badPlayer)
		cout << MenuInfo << endl;
	else
		cout << MenuBadInfo << endl;

	// コマンド入力
	string command;
	command = GetLine();

	if (CheckCommand(command, "yes", "y"))state = (badPlayer) ? VIOLATION_GAME : PLAY;
	if (CheckCommand(command, "no", "n") || CheckCommand(command, "exit", "e"))state = EXIT;
}

/// <summary>ゲーム本編</summary>
void GameManager::PlayGame()
{
	std::system("cls");

	deck.ShowAciveCard();
	drawCard = deck.GetCard();

	// スコア表示
	cout << "<< SCORE  " << right << setw(15) << score << "  >>" << endl << endl << endl;

	if (debugMode)cout << "Next -->" << left << setw(9) << drawCard.GetMarkToString() << left << setw(2) << drawCard.GetNumber() << endl;
	else cout << endl;

	// 場のカード・メニュー表示
	cout << "Show  >> " << left << setw(9) << nowCard.GetMarkToString() << left << setw(2) << nowCard.GetNumber() << endl;
	cout << "high( h ) /  Low( l )" << endl;

	if (AutoWin)cout << "I often found." << endl;

	// コマンド入力中の経過時間でスコア算出
	// 早く判断した分だけ高得点
	clock_t start = clock();
	string command;
	command = GetLine();
	clock_t end = clock();

	// コマンド判定
	if (CheckCommand(command, "debug", "d"))
	{
		debugMode = !debugMode;
		return;
	}

	if (CheckCommand(command, "exit", "e"))state = EXIT;
	if (CheckCommand(command, IOftenFound))AutoWin = true;

	int myJudg = NONE, result = NONE;
	if (CheckCommand(command, "high", "h"))myJudg = HIGH;
	if (CheckCommand(command, "low", "l"))myJudg = LOW;

	if (myJudg == NONE)return;

	// High/Lowの判定処理
	if (nowCard.GetNumber() < drawCard.GetNumber())result = HIGH;
	else if (nowCard.GetNumber() == drawCard.GetNumber())result = myJudg;
	else result = LOW;

	cout << "Check >> " << left << setw(9) << drawCard.GetMarkToString() << left << setw(2) << drawCard.GetNumber() << endl;

	// 勝敗分岐
	if (myJudg == result || AutoWin)
	{
		cout << "Win!!" << endl;
		score += BaseScore - floor((double)((end - start) / CLOCKS_PER_SEC));
	}
	else
	{
		cout << "Lose" << endl;
		state = END;
	}

	Sleep(2 * 1000);

	nowCard = drawCard;

	// ゲームセット判定
	if (deck.GameSet()) {
		state = END;
		return;
	}

	deck.Next();
}

/// <summary>ゲーム終了</summary>
void GameManager::GameEnd()
{
	std::system("cls");

	if (!badPlayer)
	{
		// リザルト表示
		cout << endl << "<< SCORE  " << right << setw(15) << score << "  >>" << endl << endl << endl;

		if (deck.GameSet())cout << GOOD_JOB;

		cout << "Menu( m ) / End( e )" << endl;
	}
	else
	{
#pragma region VIOLATION
		string message[] = { "終わり( e )","しゅうりょう( え )","End( e )" };
		int len = arraySize(message);
		srand((unsigned int)time(NULL));
		int length = rand() % 500 + 100, index = 0;

		cout << "<< SCORE  " << Garble(20) << "  >>" << endl << endl << endl;

		for (int i = 0; i < length; i++) {
			index = rand() % len;
			cout << message[index];
		}
		cout << endl << endl << endl;
		cout << "Menu( m )" << endl;
#pragma endregion
	}

	// コマンド判定
	string command;
	command = GetLine();

	if (CheckCommand(command, "menu", "m"))state = MENU;
	if (CheckCommand(command, "end") || CheckCommand(command, "exit", "e"))state = EXIT;
}

#pragma region VIOLATION
void GameManager::ViolationStart()
{
	std::system("cls");
	badPlayer = true;
	cout << "あなたの操作に不正の可能性を検出しました。\n\n\n\n\n";
	Sleep(2 * SEC);
	std::system("cls");
	cout << AA_HORROR;
	Sleep(0.5 * SEC);
	state = END;
	ViolationIndex = 0;
	GetProcess();
}

/// <summary>
/// 操作違反をした際に始まるゲーム
/// </summary>
void GameManager::ViolationGame()
{
	std::system("cls");

	deck.ShowAciveCard();
	drawCard = deck.GetCard();

	cout << "<< SCORE  " << right << setw(15) << score << "  >>" << endl << endl << endl << endl;

	switch (ViolationIndex)
	{
	case VIO_MESSAGE_5:
	{
		tm now = GetNowTime();
		printf(ViolationMessage[ViolationIndex], now.tm_hour, now.tm_min);
	}
	break;

	case VIO_MESSAGE_6:
	{
		tm now = GetNowTime();
		int hour = now.tm_hour;
		int state = 0;

		if (4 <= hour && hour < 12)state = MORNING;
		else if (12 <= hour && hour < 16)state = NOON;
		else if (16 <= hour && hour < 19)state = EVENING;
		else if (19 <= hour && hour <= 23)state = NIGHT;
		else state = MIDNIGHT;

		printf(ViolationMessage[ViolationIndex], TimeMessage[state].c_str());
	}
	break;

	case VIO_MESSAGE_14:
		printf(ViolationMessage[ViolationIndex]);
		printf("Yes( y ) /  No( n )\n");
		break;

	case VIO_MESSAGE_15:
		printf(ViolationMessage[ViolationIndex], NeedScore[userReply].c_str());
		break;

	case VIO_MESSAGE_18:
		printf(ViolationMessage[ViolationIndex], Garble(10).c_str());
		break;
	case VIO_MESSAGE_24:
		printf(ViolationMessage[ViolationIndex], Garble(5).c_str());
		break;
	case VIO_MESSAGE_25:
		printf(ViolationMessage[ViolationIndex], Garble(7).c_str());
		break;
	case VIO_MESSAGE_26:
		printf(ViolationMessage[ViolationIndex], Garble(10).c_str());
		break;
	case VIO_MESSAGE_27:
		printf(ViolationMessage[ViolationIndex], Garble(15).c_str());
		break;
	case VIO_MESSAGE_28:
		printf(ViolationMessage[ViolationIndex], Garble(20).c_str());
		break;

	case VIO_MESSAGE_29:
	{
		TCHAR user[UNLEN + 1];
		DWORD unlen = UNLEN;

		if (!GetUserName((LPTSTR)user, &unlen))
			printf(ViolationMessage[ViolationIndex], Garble(5).c_str());			//printf("Error: %u", GetLastError());
		else
			printf(ViolationMessage[ViolationIndex], user);
	}
	break;

	case VIO_MESSAGE_33:
		if (FindProcess("chrome.exe"))
			printf(ViolationMessage[ViolationIndex], "Chrome", SearchEngine.c_str());
		else
			printf(ViolationMessage[ViolationIndex], Garble(5).c_str(), Garble(5).c_str());
		break;

	case VIO_MESSAGE_34:
		if (FindProcess("lineapp.exe"))
			printf(ViolationMessage[ViolationIndex], "Line", ChatApp.c_str());
		else
			printf(ViolationMessage[ViolationIndex], Garble(5).c_str(), Garble(5).c_str());
		break;

	case VIO_MESSAGE_35:
		if (FindProcess("GameBar.exe"))
			printf(ViolationMessage[ViolationIndex], ChatApp.c_str(), "GameBar");
		else
			printf(ViolationMessage[ViolationIndex], Garble(5).c_str(), Garble(5).c_str());
		break;

	default:
		if (ViolationIndex < VIO_MESSAGE_40) {
			printf(ViolationMessage[ViolationIndex]);
		}
		else {
			MsgRed(); // 背景色：赤
			printf(ViolationMessage[ViolationIndex]);
			MsgWhite(); // 背景色：緑
		}
		break;
	}
	printf("\n");

	cout << "Show  >> " << left << setw(9) << nowCard.GetMarkToString() << left << setw(2) << nowCard.GetNumber() << endl;
	cout << "high( h ) /  Low( l )" << endl;

	string command;
	command = GetLine();

	int myJudg = NONE, result = NONE;
	if (CheckCommand(command, "high", "h"))myJudg = HIGH;
	if (CheckCommand(command, "low", "l"))myJudg = LOW;

	if (ViolationIndex == VIO_MESSAGE_14) {
		userReply = NS_NONE;
		if (CheckCommand(command, "yes", "y"))userReply = NS_YES;
		if (CheckCommand(command, "no", "n"))userReply = NS_NO;
	}

	//if (myJudg == NONE)return;

	if (nowCard.GetNumber() < drawCard.GetNumber())result = HIGH;
	else if (nowCard.GetNumber() == drawCard.GetNumber())result = myJudg;
	else result = LOW;

	if (myJudg == result)
		cout << "Check >> " << left << setw(9) << drawCard.GetMarkToString() << left << setw(2) << drawCard.GetNumber() << endl;
	else
		cout << "Check >> " << Garble(11) << endl;

	cout << "Win!!" << endl;
	score += 999;

	Sleep(2 * 1000);

	nowCard = drawCard;

	if (deck.GameSet()) {
		state = VIOLATION_END;
		return;
	}

	ViolationIndex++;
	deck.Next();
}

void GameManager::ViolationEnd()
{
	MsgRed(); // 背景色：赤

	system("cls");

	cout << endl << "<< SCORE  " << right << setw(15) << score << "  >>" << endl << endl << endl;
	if (deck.GameSet())cout << GOOD_JOB;
	cout << "Menu( m ) / Menu( m )" << endl;

	string command;
	command = GetLine();

	//if (CheckCommand(command, "menu", "m"))state = MENU;
	//if (CheckCommand(command, "end") || CheckCommand(command, "exit", "e"))state = MENU;

	MsgWhite(); // 背景色：緑

	state = VIOLATION_MENU;
}

void GameManager::ViolationMenu()
{
	system("cls");

	deck.Init();
	deck.Shuffle();
	score = 0;
	AutoWin = false;
	nowCard = deck.GetCard();
	deck.Next();

	cout << CanNotTurnBack << endl;

	string command;
	command = GetLine();
	//string command;
	//command = GetLine();

	//if (CheckCommand(command, "yes", "y"))state = (badPlayer) ? VIOLATION_GAME : VIOLATION_GAME;//PLAY;
	//if (CheckCommand(command, "no", "n") || CheckCommand(command, "exit", "e"))state = EXIT;

	system("cls");
	Sleep(3000);

	MsgRed(); // 背景色：赤

	printf("\n\n\n\n");
	printf("            <(o)>");
	printf("\n\n\n\n");

	Sleep(1000);
	system("cls");

	printf("\n\n\n\n");
	printf("            ____");
	printf("\n\n\n\n");

	Sleep(1000);
	system("cls");

	printf("\n\n\n\n");
	printf("            <(o)>");
	printf("\n\n\n\n");

	Sleep(500);
	system("cls");

	printf("\n\n\n\n");
	printf("            ____");
	printf("\n\n\n\n");

	Sleep(1000);
	system("cls");

	printf("\n\n\n\n");
	printf("            <(o)>");
	printf("\n\n\n\n");

	Sleep(1000);

	MsgWhite(); // 背景色：緑
	system("cls");
	state = EXIT;
}

string GameManager::Garble(int length)
{
	srand((unsigned int)time(NULL));

	string ss[] = { "縺ｨ","倶","◆","∪","?","諤","＞","悶","∫","┌" ,"驕","贋","ｸ","九","竇","纛","襲","爨","驪","逢","竃","曩","ぇ","穐","ぼ","悪" };
	string result = "";
	int len = ss->length();
	int index = 0;

	for (int i = 0; i < length; i++) {
		index = rand() % len;
		result += ss[index];
	}

	return result;
}

tm GameManager::GetNowTime()
{
	time_t timer = time(nullptr);
	struct tm now;
	errno_t error;

	error = localtime_s(&now, &timer);

	return now;
}

void GameManager::GetProcess()
{
	DWORD allProc[1024];
	DWORD cbNeeded;
	int nProc;

	processList.clear();

	if (!EnumProcesses(allProc, sizeof(allProc), &cbNeeded))return;

	nProc = cbNeeded / sizeof(DWORD);

	for (int i = 0; i < nProc; i++) {
		TCHAR procName[MAX_PATH] = TEXT("<unknown>");
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, allProc[i]);

		if (hProcess != NULL) {
			HMODULE hMod;
			DWORD cbNeeded;

			if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
				GetModuleBaseName(hProcess, hMod, procName, sizeof(procName) / sizeof(TCHAR));
			}
		}

		processList.push_back(procName);
		//_tprintf(TEXT("%s (PID: %u)\n"), procName, allProc[i]);
		CloseHandle(hProcess);
	}
}

bool GameManager::FindProcess(string name)
{
	auto itr = find(processList.begin(), processList.end(), name);
	if (itr != processList.end())return true;
	return false;
}
#pragma endregion

/// <summary>標準入力</summary>
string GameManager::GetLine()
{
	// 標準入力
	string ss;
	getline(cin, ss);

	// 違反者分岐
	int limit = 100;
	if (ss.length() >= limit)
	{
		state = VIOLATION_START;
		ss = "";
	}

	return ss;
}

/// <summary>コマンドチェック 大文字小文字は許容する</summary>
bool GameManager::CheckCommand(string command, string check, string check2)
{
	for (size_t ch = command.find_first_of(" "); ch != string::npos; ch = ch = command.find_first_of(" "))
		command.erase(ch, 1);

	if (!check2.empty())
		return regex_match(command, regex(check, regex::icase)) || regex_match(command, regex(check2, regex::icase));

	return regex_match(command, regex(check, regex::icase));
}
#pragma endregion

/// <summary>メイン</summary>
int main()
{
	// ウィンドウタイトル
	SetConsoleTitle("High & Low");

	// ウィンドウ最大表示
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_MAXIMIZE);
	SendMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);

	// ゲームインスタンス生成
	GameManager GM = GameManager();
	GM.MainLoop();

	return 0;
}


